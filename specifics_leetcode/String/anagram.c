// Note : assuming string is in lowercase
// Remember : ascii of a is 97
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isAnagram(char *s, char *t) {
    int m = strlen(s), n = strlen(t),i ;
    if(m != n) return 0; // if size is not same, then not anagram.
    int *hash = (int*)malloc(26 * sizeof(int));
    for(i=0;i<m;i++) hash[s[i]-97]++;
    for(i=0;i<n;i++) hash[t[i]-97]++;
    for(i=0;i<26;i++) if(hash[i] > 0 && (hash[i] & 1)) return 0;  // if element is odd, then not anagram.
    return 1;
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        char s[50], t[50];
        scanf("%s%s",s,t);
        isAnagram(s, t) == 1 ? printf("Strings are panagram.") : printf("Strings are not panagram.");
        printf("\n");
    }
    return 0;
}
