Also refer to highlights in the browser.

## TODO
- Unread Links
	- https://portforward.com/
	- https://webpack.js.org/guides/
	- https://webpack.js.org/concepts/
	- https://docs.npmjs.com/
	- https://www.npmjs.com/package/sfs2x-api
	- https://en.wikipedia.org/wiki/File_descriptor
	- https://www.tecmint.com/increase-set-open-file-limits-in-linux/
	- https://en.wikipedia.org/wiki/Network_address_translation
	- https://en.wikipedia.org/wiki/Syntactic_sugar
	- https://en.wikipedia.org/wiki/Don%27t_repeat_yourself
	- https://en.wikipedia.org/wiki/WebSocket
	- https://en.wikipedia.org/wiki/HTTP_tunnel
	- https://en.wikipedia.org/wiki/Netstat
	- https://jumpcloud.com/blog/how-to-create-a-new-sudo-user-manage-sudo-access-on-ubuntu-20-04
	- https://unix.stackexchange.com/questions/18209/detect-init-system-using-the-shell
	- https://docs.hetzner.com/robot/dedicated-server/troubleshooting/network-diagnosis-and-report-to-hetzner/
	- https://www.tcpipguide.com/free/t_TCPConnectionTermination-2.htm
	- https://www.tldp.org/HOWTO/SSL-Certificates-HOWTO/x64.html
	- https://en.wikipedia.org/wiki/Certificate_authority
	- https://www.openssl.org/community/binaries.html
	- https://www.digicert.com/help/

## Notes
- sfs-config.xml
- client: game, mmo and buddylist
- server: SFSApi, SFSGameApi, MMOApi, SFSBuddyApi, SFSZone, SFSRoom, SFSUser, SFSObject, SFSArray,SFSRoomVariable, SFSUserVariable
- connect, login to zone (permissions) (default vs custom login, determine in zone configurator), roomcreation api (permissions), room groups (better performance), Room Variable, Room created and removedevents, ex: chat group - game group
- Privilege Manager offered by SFS2X you can also limit specific type of users (guest, regular, moderator,etc) to access certain controller's features.
- configuration services, logging, security, task scheduling, zone/room/user management, buddy lists,banned user management, remote administration, email services, HTTP services, database integration, gameinvitations, User and Room matching
- BitSwarm: provides binary protocol with dynamic compression, UDP support, JMX monitoring, transparentreconnection system, high performance http-tunnelling and heaps
- http://docs2x.smartfoxserver.com/Overview/sfs2x-features
- 9933, 9933/udp, 8080, 8443, tls, tcp, bluebox, websocket
- The SmartFox.InitCrypto method is not available when building for WebGL: use WSS connection.
- to encrypt traffic of 9933/tcp: enable Zone's encryption settings + SmartFox.InitCrypto()
- config.port = useEncryption ? 8443 : 8080;		config.useSSL = useEncryption
- log files (SFS2X/logs/), bluebox log folder: SFS2X/logs/http/, https://www.smartfoxserver.com/productsanalytics#p=intro  , Encrypt database data, Storage encryption
- {SFS2X}/config/log4j.properties	log4j.category.com.smartfoxserver=INFO,consoleAppenderfileAppender			(save the changes and restart SFS2X.)
- {SFS2X}/config/log4j.properties	log4j.appender.fileAppender.DatePattern=''yyyy-MM-dd						(save the changes and restart SFS2X.)
- <script type="text/javascript" src="libs/sfs2x-api-1.7.11.js"></script>
	- npm installsfs2x-api --save
	- import * as SFS2X from "sfs2x-api";
	- webpack
- Enable blubox on client side: <SmartFoxConfig></SmartFoxConfig>
	- The BlueBox failover mechanism applies only for TCP based clients. Websocket clients are not supported.
	- HRC is not available for HTML5/WebGL clients.
	- CONNECTION_RETRY, CONNECTION_RESUME, CONNECTION_LOST, SFSEventType.USER_RECONNECTION_TRY and 	SFSEventTypeUSER_RECONNECTION_SUCCESS
	- client: killConnection()
- SFSEvent.LOGIN_ERROR: http://docs2x.smartfoxserver.com/DevelopmentBasics/login-phase
	- Auto-subscribe the default Room Groups, Populate the client with the initial Room List
- Room
	- JoinRoomRequest, ROOM_JOIN, ROOM_JOIN_ERROR
	- SFSEvent.ROOM_JOIN_ERROR: Room is full, Room doesn't exist, Wrong password
	- lastJoinedRoom, joinedRooms, roomManager
	- ? I have some questions here.
	- create room dynamically: SFSEvent.ROOM_ADD, SFSEvent.ROOM_CREATION_ERROR, SFS2X.RoomSettings,settings.maxUsers, settings.groupId, SFS2X.CreateRoomRequest
	- SFSEvent.ROOM_CREATION_ERROR: Lack of User Permission, Duplicate Room name, Bad words in Room name,Maximum number of user-created Rooms is reached, Maximum number of Rooms in the Zone is reached
	- Regular Rooms: isGame = false
	- Game Rooms: isGame = ture, Automatic assignment of player IDs, Support for non-player users(spectators), SpectatorToPlayerRequest, PlayerToSpectatorRequest
	- MMO Rooms
- SchedulerTestExtension
- ? http://docs2x.smartfoxserver.com/Overview/white-papers
- ? http://docs2x.smartfoxserver.com/GettingStarted/web-sockets
- ? https://smartfoxserver.com/blog/sfs2x-and-node-js/
- ? http://docs2x.smartfoxserver.com/GettingStarted/admintool
- ? http://docs2x.smartfoxserver.com/GettingStarted/reconnection-hrc-plus
- ? http://docs2x.smartfoxserver.com/GettingStarted/troubleshooting
- ? http://docs2x.smartfoxserver.com/GettingStarted/redbox
- TODO from http://docs2x.smartfoxserver.com/DevelopmentBasics/join-and-create-rooms , 	Roomarchitecture		Server Variables		SFSObject/SFSArray		HOWTOs
- http://docs2x.smartfoxserver.com/ExamplesFlash/tris
- http://docs2x.smartfoxserver.com/ExamplesFlash/spacewar
- http://docs2x.smartfoxserver.com/ExamplesFlash/battlefarm
- http://docs2x.smartfoxserver.com/ExamplesFlash/space-race
- https://smartfoxserver.com/blog/
- http://docs2x.smartfoxserver.com/api-docs/jsdoc/client/
- http://docs2x.smartfoxserver.com/api-docs/javadoc/server/com/smartfoxserver/v2/api/SFSApi.html
- https://smartfoxserver.com/blog/how-to-setup-a-connection-to-an-external-database/