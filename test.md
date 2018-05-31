# Test

## Builtin

### cd
1. Classic

	- `cd /abs/path`
	- `cd /wrong/abs/path`
	- `cd ./relv/path`
	- `cd ./relv/wrong/path`

1. Cdpath
	- `cd folder_of_cdprath` with `cdpath set`
	- `cd folder_of_cdprath` with `cdpath unset`

1. Special

	- `cd -` move to the previous PWD
	- `cd` move to home

1. Error

	- `unset OLDPWD` and `cd -` > display error
	- `unset HOME` and `cd` > display error

	- `set OLDPWD with wrong path` and `cd -` > display error
	- `set HOME with wrong path` and  `cd` > display error

### echo
1. Classic

	- `echo`
	- `echo la`
	- `echo la la`
	- `echo -n`
	- `echo -n la`
	- `echo -n la la`

1. Special
	- `echo --`
	- `echo -na`
	- `echo -- -n`
	- `echo -n --`

### exit
1. Classic

	- `exit` > return value : `the previous one`
	- `exit 42` > return value : `42`
	- `exit 257` > return value : `1`
	- `exit 128` > return value : `128`
	- `exit 256` > return value : `0`

1. Special

	- `exit bla`

1. Error
	- `exit bla bla` > too much argument

### env
1. Classic

	- `env`
	- `env -i`

1. Binary

	- `env ls`
	- `env env`
	- `env -i ls`
	- `env -i env`

1. Argument

	- `env key=value`
	- `env -i key=value`
	- `env key=value ls`
	- `env key=value env`
	- `env -i key=value ls`
	- `env -i key=value env`

1. Fun

	- `env env -i env HOME=test env HOME=yo bash -c "echo \$HOME"`

### setenv
1. Classic

	- `setenv key=value`
	- `setenv key=value key1=value1`
	- `setenv test=`

1. Error

	- `setenv key value`
	- `setenv key=value test`
	- `setenv =test`

### unsetenv
1. Classic

	- `unsetenv thatnotexits`
	- `unsetenv thatexits`
	- `unsetenv key1 key2 ...`

### export
1. Classic

	- `export key=value`
	- `export key`
	- `export key1 key2 ...`

1. Error
	- `export =value`

### set
1. Classic

	- `set key=value`
	- `set key`
	- `set key1 key2 ...`

1. Error

	- `set =value`

### unset
1. Classic

	- `unset thatnotexits`
	- `unset thatexits`
	- `unset key1 key2 ...`

### history
1. Classic

	- `history`

1. Read

	- `history -r`
	- `history -r filethatexist`

1. Write

	- `history -w`
	- `history -w filethatexist`
	- `history -w filethatnotexist`

1. Append

	- `history -a`
	- `history -a filethatexist`
	- `history -a filethatnotexist`

1. Error

	- `history -r filethatnotexit`
	if home not set
	- `history -r`
	- `history -w`
	- `history -a`

## Exe

- `false || flase && false || echo true` > true
- `echo 1 || echo 2 && echo 3 || echo 4` > 1 3
- `echo 1 && echo 2 && echo 3 || echo 4` > 1 2 3
- `echo 1 || echo 2 && echo 3 && echo 4` > 1 3 4
- `ls ; ls`
- `ls -l ; touch t; ls -l`
- `yo || ls -l; touch c ; ls && rm c ; ls || echo nothing`

## Pipe

- `ls | cat`
- `ls | cat -e`
- `cat | ls | cat -e`
- `cat -e | ls | cat -e`
- `base64 /dev/random | head -c 1000 | grep 42`
- `cat /dev/random | ls`
- `ls -R | grep e | sort`

## Redir
