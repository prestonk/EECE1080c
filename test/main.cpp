#include <iostream>

using namespace std;



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



int main()
{
    cout << SubstitutionCipher("qwertyuiopasdfghjklzxcvbnm", 'z') << endl;
    cout << ReverseSubstitutionCipher("qwertyuiopasdfghjklzxcvbnm", 'm') << endl;
    return 0;
}
