#include <stdio.h>
#include <time.h>
#include <hpsecurity.h>
#include <prot.h>

/* Compile with: cc -o passgen passgen.c -lsec */

   /* 1st param is the desired password  */
   /* A random seed (2 chars) will be    */
   /* automatically chosen.              */
   /* For good passwords:                */
   /*     Use random chars, mixed apha-  */
   /*     numerics and MiXeD CaSe for    */
   /*     better protection.             */

main(argc, argv)
int argc;
char *argv[];
{
  char salt[3];
  char *EncryptedPasswd;
  int CheckRand;
  int Fixup;
  int SeedChar;

  if ( (argc < 2) || (argc > 3) ) 
  {
    printf("\nUsage: %s <password_to_encrypt> [seed]\n",argv[0]);
    exit(64);
  }

  if ( argc > 2 )
  { 
    salt[0] = argv[2][0];
    salt[1] = argv[2][1];
    salt[2] = '\0';
  } 
  else
  {
    /* Generate a random starting point for seed charcaters */

    srand(time(NULL));
    for ( SeedChar = 0; SeedChar <= 1; SeedChar++) 
    {
      CheckRand = 46 + rand() % 76;   /* random from 46 to 122  */
      Fixup = 7 + rand() % 13;          /* random from 7 to 20    */
      salt[SeedChar] = toascii(((CheckRand >= 58 && CheckRand <= 64) 
  	|| (CheckRand >= 91 && CheckRand <= 96) 
 	 ? CheckRand + Fixup : CheckRand));
    }
  }

  EncryptedPasswd=bigcrypt(argv[1], salt);    
  printf("%s\n", 
          EncryptedPasswd);
}
