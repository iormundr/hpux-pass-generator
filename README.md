# hpux-pass-generator
HPUX password generator

If you are looking for a hashed password for users to be created on HPUX servers this is it.



Just compile  `cc -o passgen passgen.c -lsec`

Usage:
```
./passgen
Usage: ./passgen <password_to_encrypt> [seed]
```
Example: 
```
hpux1 :/app # ./passgen Test123!
MkfUEAsjrDPYM
```

###### Now you can use it in useradd
```
useradd -u 5123 -g app -d /app/tstusr -s /usr/bin/ksh -c Test_Account -m -p MkfUEAsjrDPYM tstusr
```
