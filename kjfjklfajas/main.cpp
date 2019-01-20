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


void RotateCipherKey(string &cipher_key)
{
  char first_char = cipher_key[0];
  for (int x = 1; x <= 25; x++) {
    cipher_key[x-1] = cipher_key[x];
  }
  cipher_key[25] = first_char;
}

void ReverseRotateCipherKey(string &cipher_key)
{
  char first_char = cipher_key[25];
  for (int x = 1; x <= 25; x++) {
    cipher_key[x] = cipher_key[x+1];
  }
  cipher_key[0] = first_char;
}













int main()
{
    string cypher = "qwertyuiopasdfghjklzxcvbnm";
    string cypher2 = "qwertyuiopasdfghjklzxcvbnm";
    cout << EncryptString(cypher, "this is some random gibberish") << endl;
    cout << DecryptString(cypher2, "zoac fn qbvh tgezyt qrbnejozp");
    return 0;
}
