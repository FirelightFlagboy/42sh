# 42sh
##
the project 42sh
- [Pdf](https://cdn.intra.42.fr/pdf/pdf/183/42sh.fr.pdf)

# Man
##
- [Man](https://github.com/adibk/42sh_team_2018/blob/master/Man2.md)

# Keybinding

| key binding | description | lvl implementation |
| --- | --- | --- |
| `ctrl + p` | paste the `clipboard` | done |
| `ctrl + k` | cut to the left of the `cursor` | done |
| `ctrl + l` | clear the console | done |
| `ctrl + i` | completion | done |
| `ctrl + u` | move to the end of command | done |
| `ctrl + h` | copy the command | done |
| `home` | move to the begin of the command | done |
| `end` | move to the end of the command | done |
| `left arrow` | move the `cursor` to the left | done |
| `right arrow` | move the `cursor` to the right | done |
| `alt + left arrow` | move the `cursor` to the previous word of the `command` | done, but the key binding seems to only work on `Iterm` |
| `alt + right arrow` | move the `cursor` to the next word of the `command` | done, but the key binding seems to only work on `Iterm` |
| `up arrow` | get the last command of the history | done |
| `down arrow | get the next command of the history | done |

# Bonus
##
| Bonus | description | status |
| --- | --- | --- |
| inhibiteurs | """ (double quote), "’" (simple quote) et "\" (backslash) | done |
| redirections avancées | l’aggrégation des sorties de fichier et le heredoc "<<". | missing fd |
| globing | "*", "?", "[]", "{}", etc. (sans utiliser la fonction glob(3) !) | not done |
| backquotes | `` ` `` | not done |
| subshell |  les operateurs "()". | not done |
| local variable | les builtin unset et export. | not done |
| history | L’historique des commandes et les builtins history et "!" | done |
| line edition | Edition de ligne telle que demandée dans le ft_sh3. | done |
| file des & read builtin | Les descripteurs de fichiers et la builtin read avec toutes ses options | not done |
| dynamique completion | all in the tittle | done |
| job control | les builtins jobs, fg et bg, et l’operateur "&" | in progress |
| shell script | in the tittle | not done |

## Other
##
| Bonus | description | status |
| --- | --- | --- |
| `completion` | mini select | use |
| `hash` | an hash table to speed up the exe | use |
| `ast` | ast tree | use |
| `debug hash` | debug function | use |
| `debug ast` | debug function | use |
| `debug argv` | debug function | use |
| `multiline` | multiline edition | use |
| `"` | double quote | use |
| `'` | simple quote | use |
| `\` | escape char | use |
| `` ` `` | back quote | use |
| `escape` | escape char | use |
| `prompt` | line prompt | use |
| `set` | builtin set | use |
| `!?word?` | search word in history | use |
| `!!` | lauch previous command | use |
| `!-1` | lauch previous command | use |
| `!nb` | lauch command at index nb | use |
| `!word` | lauch command word | use |
| `history -r` | option non posix | use |
| `history -w` | option non posix | use |
| `history -a` | option non posix | use |
| `read -h` | option non posix | use |
| `read -u` | option non posix | use |
| `read -d` | option non posix | use |
| `read -p` | option non posix | use |
| `cmd + v` |
