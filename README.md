# cybersecurity-simple-attacks
in this repo i will implement some simple crypto attacks such as brute force attack and dictionary attack on C language to take advantage of its speed

# dictionnary attack :
in this version of the dictionary attack we will use a 1 million version of the famous rockyou dictionary to crack md5 hashes , in order to use it first define your target , lets say the word "password" , start by hashing it using the commande :</br>
echo "password" | md5
this will give you the hash of the word "password" : 5f4dcc3b5aa765d61d8327deb882cf99
then  run the DictAttack.c file using the command :
clang DictAttack.c md5.c -o DictAttack -l crypto
which will create the application DictAttack
now to check if the unhash the hash : 5f4dcc3b5aa765d61d8327deb882cf99
just run the command :
./DictAttack 5f4dcc3b5aa765d61d8327deb882cf99
This will hash every word in the rockyou1m.txt and compare its hash with the one you provide , once they matches , it will return the word that hashing it produce the same hash as your target hash

# brute force attack :
this attack works by generating all the possible combinations of characters , hashing them and comparing the result with the target hash , once they matches , it will return the word that hashing it produce the same hash as your target hash
this attack is simple and only works with passwords from 5 lowercase alphabets , define your target as discribed previously in the dictionnary attack ,
, then place the target hash on the target variable in the bruteForce.c file :
for example the hash of the word "halab" is : 2518907025e27330286b1981ce79855c
inside the file we will define as target : 
#define target "2518907025e27330286b1981ce79855c"
then run the file using the command :
 clang bruteForce.c md5.c -o bruteforce -l crypto
 once the application bruteForce is created , we can lunch the attack using the command :
 ./bruteForce
 
 hope it works for you

