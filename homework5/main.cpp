// Name: Preston Knibbe
//
// Purpose: To demostrate string functions by using basic crytopgraphy  methods
//


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

char substitution_cipher(string cipher_key, char char_to_encrypt);
char reverse_substitution_cipher(string cipher_key, char char_to_encrypt);

string EncryptString(string &cipher_key, string string_to_be_encrypted);
string DecryptString(string &cipher_key, string string_to_be_decrypted);

void RotateCipherKey(string &cipher_key);
void DisplayFile(string filename, string cipher_key);


void EncryptFile(string cipher_key, string filename_from, string filename_to);
void DecryptFile(string cipher_key, string filename_from, string filename_to);

int main()
{
	string cipher_key = "qwertyuiopasdfghjklzxcvbnm";
  string cipher_key2 = "qwertyuiopasdfghjklzxcvbnm";
	EncryptFile(cipher_key, "test.txt", "test-encrypted.txt");
	DecryptFile(cipher_key2, "test-encrypted.txt", "test-ed.txt");
	DisplayFile("test.txt", cipher_key2);
	DisplayFile("test-encrypted.txt", cipher_key2);
	DisplayFile("test-ed.txt", cipher_key2);

	return 0;
}


//  Rotate the cipher key. Example: abcdef becames bcdefa
//
// Note: Call by reference
void RotateCipherKey(string &cipher_key)
{
  char first_char = cipher_key[0];
  for (int x = 1; x <= 25; x++) {
    cipher_key[x-1] = cipher_key[x];
  }
  cipher_key[25] = first_char;
}

// Perform a substitution cipher on a single character
// using the specified cipher key
// See reference document for implementation details.
char SubstitutionCipher(string cipher_key, char char_to_encrypt)
{
  char finder[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
  'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
  's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  char encrypted_char;
	for(int x = 0; x <= 26; x++) {
    if (finder[x] == char_to_encrypt) {
      encrypted_char = cipher_key[x];
    }
	}
	return encrypted_char;
}

// Perform a "reverse" substitution cipher on a single character
// using the specified cipher key
// See reference document for implementation details.
char ReverseSubstitutionCipher(string cipher_key, char char_to_decrypt)
{
  char finder[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
  'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
  's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  char decrypted_char;
  for (int x = 0; x <= 26; x++) {
    if (cipher_key[x] == char_to_decrypt) {
      decrypted_char = finder[x];
    }
  }
	return decrypted_char;
}

// Encrypt String and return it
// You will use the SubstitutionCipher() function to encrypt the
// individual characters
//
// Note: You have to call RotateCipherKey() after each time you encrypt
// a character.
string EncryptString(string &cipher_key, string string_to_be_encrypted)
{
  string encrypted_string = "";
  for (int x = 0; x < string_to_be_encrypted.length(); x++) {
    encrypted_string += SubstitutionCipher(cipher_key, string_to_be_encrypted[x]);
    RotateCipherKey(cipher_key);
  }

	return encrypted_string;
}

// Decrypt String and return it
// You will use the ReverseSubstitutionCipher() function to decrypt the
// individual characters
//
// Note: You have to call RotateCipherKey() after each time you encrypt
// a character.
string DecryptString(string &cipher_key, string string_to_be_decrypted)
{

	string decrypted_string = "";
  for (int x = 0; x < string_to_be_decrypted.length(); x++) {
    decrypted_string += ReverseSubstitutionCipher(cipher_key, string_to_be_decrypted[x]);
    RotateCipherKey(cipher_key);
  }


	return decrypted_string;
}

// Display file specified by the filname parameter

void DisplayFile(string filename, string cipher_key)
{
	string input;
	ifstream infile;

	infile.open (filename.c_str());

 	if(!infile)
    {
		cout << "Can not open input file " + filename << endl;
		exit(0);
    }

	while( getline(infile, input))
    {
		cout << EncryptString(cipher_key,  input) << endl;
	}
	infile.close();
}


// Encrypt the specified file using the specified cipher key and
// write the output to a different file
// This function is complete
void EncryptFile(string cipher_key, string filename_from, string filename_to)
{
	string input;
	ifstream infile;
	ofstream outfile;

	infile.open (filename_from.c_str());
	outfile.open (filename_to.c_str());

 	if(!infile)
        {
		cout << "Can not open input file " + filename_from << endl;
		exit(0);
        }

 	if(!outfile)
        {
		cout << "Can not open Output file " + filename_to << endl;
		exit(0);
        }


	while( getline(infile, input))
        {
		outfile << input << endl;
	}
	infile.close();
	outfile.close();
}

// Decrypt the specified file using the specified cipher key and
// write the output to a different file
// This function is complete
void DecryptFile(string cipher_key, string filename_from, string filename_to)
{
	string input;
	ifstream infile;
	ofstream outfile;

	infile.open (filename_from.c_str());
	outfile.open (filename_to.c_str());

 	if(!infile)
        {
		cout << "Can not open input file " + filename_from << endl;
		exit(0);
        }

 	if(!outfile)
        {
		cout << "Can not open Output file " + filename_to << endl;
		exit(0);
        }


	while( getline(infile, input))
        {
		outfile << DecryptString(cipher_key,  input) << endl;
	}
	infile.close();
	outfile.close();
}
