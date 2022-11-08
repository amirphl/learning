// https://quera.org/contest/assignments/45366/problems/157571

package keyboard

type Keyboard struct {
	dure  int
	state map[rune]int
}

func NewKeyboard(dure int) *Keyboard {
	return &Keyboard{
		dure,
		make(map[rune]int),
	}
}

func (keyboard *Keyboard) Enter(inp string) string {
	out := make([]rune, 0)
	shift := rune(16)

	for _, c := range inp {
		if 'A' <= c && c <= 'Z' {
			lower := c + 32
			if keyboard.state[shift] < keyboard.dure {
				keyboard.state[shift]++
				if keyboard.state[lower] < keyboard.dure {
					out = append(out, c)
					keyboard.state[lower]++
				}
			} else {
				if keyboard.state[lower] < keyboard.dure {
					out = append(out, lower)
					keyboard.state[lower]++
				}
			}
		} else if keyboard.state[c] < keyboard.dure {
			out = append(out, c)
			keyboard.state[c]++
		}
	}

	return string(out)
}
