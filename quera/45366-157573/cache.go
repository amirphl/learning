package cache

import "sync"

type Entry struct {
	V   CacheVal
	rtl int
}

type Cache struct {
	m  map[string]*Entry
	mu *sync.Mutex
}

type CacheServerConnection struct {
	UC map[string]*Cache
}

func InitCache() *Cache {
	return &Cache{
		make(map[string]*Entry),
		&sync.Mutex{},
	}
}

func handle(snd chan CacheRequest, rcv chan CacheResponse, cache *Cache) {
	for req := range snd {
		cache.mu.Lock()
		switch req.Request {
		case "Set":
			if req.RTL == 0 {
				cache.m[req.Key] = &Entry{req.Val, -1}
				rcv <- CacheResponse{}
			} else {
				cache.m[req.Key] = &Entry{req.Val, req.RTL}
				rcv <- CacheResponse{}
			}
		case "Get":
			en, ex := cache.m[req.Key]
			if ex {
				if en.rtl == -1 {
					rcv <- CacheResponse{Val: en.V}
				} else {
					en.rtl--
					rcv <- CacheResponse{Val: en.V}
					if en.rtl == 0 {
						delete(cache.m, req.Key)
					}
				}
			} else {
				rcv <- CacheResponse{}
			}
		}
		cache.mu.Unlock()
	}
	// close(rcv)
}

func (cache *Cache) Connect(name string) *CacheClientConnection {
	request := make(chan CacheRequest)
	response := make(chan CacheResponse)
	go handle(request, response, cache)

	//https://knowyourmeme.com/memes/trade-offer
	// serverConn := &CacheServerConnection{
	// TODO
	// }
	clientConn := &CacheClientConnection{
		snd: request,
		rcv: response,
	}

	//cache.connsMutex.Lock()
	//cache.conns = append(cache.conns, serverConn)
	//cache.connsMutex.Unlock()

	return clientConn
}
