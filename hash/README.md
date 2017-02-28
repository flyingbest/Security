# hash

### Hash Tables

Hash tables combine the random access ability of an array with the dynamism of a linked list. The trade off is that hash tables are not great at ordering or sorting data, but if we don't care about that, then we're good to go!

A hash table amounts to a combination of two things with which we're quite familiar.  
	- First, a **hash function**, which returns an nonnegative integer value called a hash code.  
	- Second, an **array** capable of storing data of the type we wish to place into the data structure.

How to define a hash function? Really no limit to the number of possible hash functions. Here's an example of hash function : 

```c
unsinged int hash(char* str){
	int sum = 0;
	for(int i = 0; str[i] != '\0'; i++){
		sum += str[i];
	}
	return sum % HASH_MAX;
}
```

A **Collision** occurs when two pieces of data, when run through the hash function, yield the same hash code. Presumably we want to store both pieces of data in the hash table, so we shouldn't simply overwrite the data that happened to be placed in there first. We need to find a way to get both elements into the hash table while trying to preserve quick insertion and lookup.

Resolving collision : **Linear probing**   
 - In this method, if we have a collision, we try to place the data in the next consecutive element in the array (wrapping around to the begining if necessary) until we find a vacancy.  
 - Linear probing is subject to a problem called **clustering**. Once there's a miss, two adjacent cells will contain data, making it more likely in the future that the cluster will grow. Even if we switch to another probing technique, we're still limited.  

Resolving collision : **Chaining**  
 - pull it all together.  
 - what if instead of each element of the array holding just one piece of data, it held multiple pieces of data?  
 - if each element of the array is a pointer to the head of a linked list, then multiple pieces of data can yield the same hash code and we'll be able to store it all!  
 - We know from experience with linked lists that insertion (and creation, if necessary) into a linked list is an O(1) operation.  

Including codes is simple hash table implementation.

### Hash Function

A **cryptographic hash function** is a special class of hash function that has certain properties which make it suitable for use in cryptography. It is a mathematical algorithm that maps data of arbitrary size to a bit string of a fixed size (a hash function) which is designed to also be a one-way function, that is, a function which is infeasible to invert. The only way to recreate the input data from an ideal cryptographic hash function's output is to attempt a brute-force search of possible inputs to see if they produce a match, or use a "rainbow table" of matched hashes.

### SECURE HASH ALGORITHM (SHA)

The Secure Hash Algorithm is a family of cryptographic hash functions published by the National Institute of Standards and Technology (NIST) as a U.S. Federal Information Processing Standard (FIPS), including:  

 - SHA-0: A retronym applied to the original version of the 160-bit hash function published in 1993 under the name "SHA". It was withdrawn shortly after publication due to an undisclosed "significant flaw" and replaced by the slightly revised version SHA-1.  
 - SHA-1: A 160-bit hash function which resembles the earlier MD5 algorithm. This was designed by the National Security Agency (NSA) to be part of the Digital Signature Algorithm. Cryptographic weaknesses were discovered in SHA-1, and the standard was no longer approved for most cryptographic uses after 2010.  
 - SHA-2: A family of two similar hash functions, with different block sizes, known as SHA-256 and SHA-512. They differ in the word size; SHA-256 uses 32 byte words where SHA-512 uses 64 byte words. There are also truncated versions of each standard, known as SHA-224, SHA-384, SHA-512/224 and SHA-512/256. These were also designed by the NSA.  
 - SHA-3: A hash function formerly called Keccak, chosen in 2012 after a public competition among non-NSA designers. It supports the same hash lengths as SHA-2, and its internal structure differs significantly from the rest of the SHA family.  

The corresponding standards are FIPS PUB 180 (original SHA), FIPS PUB 180-1 (SHA-1), FIPS PUB 180-2 (SHA-1, SHA-256, SHA-384, and SHA-512). NIST has updated Draft FIPS Publication 202, SHA-3 Standard separate from the Secure Hash Standard (SHS).

### SHA-1 breaks by Google

The SHA-1 algorithm produces a 160-bit mathematical representation, or hash value, that should be unique for a given file. It's been used to ensure the integrity of everything from digital certificates for HTTPS websites, to managing commits in code repositories, and protecting users against forged documents.  

Now the researchers, using a technique called [SHAttered](https://shattered.it/), have demonstrated that two PDFs with different content can have the same hash, which should never happen. "We hope that our practical attack against SHA-1 will finally convince the industry that it is urgent to move to safer alternatives such as SHA-256," the researchers said.

Link to [Google's Security Blog](https://security.googleblog.com/2017/02/announcing-first-sha1-collision.html).


