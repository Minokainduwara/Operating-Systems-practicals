#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>

// Count vowels in a string
int countVowels(char str[]){
    int count = 0;
    for(int i = 0; i < strlen(str); i++){
        char ch = tolower(str[i]);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            count++;
        }
    }
    return count;
}

// Count words
int countWords(char str[]){
    int count = 0;
    int inWord = 0;

    for (int i = 0; str[i] != '\0'; i++){
        if (!isspace(str[i]) && inWord == 0){
            inWord = 1;
            count++;
        } else if (isspace(str[i])){
            inWord = 0;
        }
    }
    return count;
}

int main(){
    char sentence[200];

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
    }
    else if (pid == 0) {
        // Child process
        int words = countWords(sentence);
        printf("Child Process: Number of words = %d\n", words);
    }
    else {
        // Parent process
        int vowels = countVowels(sentence);
        printf("Parent Process: Number of vowels = %d\n", vowels);
    }

    return 0;
}