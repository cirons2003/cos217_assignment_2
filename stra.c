#include "str.h";
#include <string.h>;

size_t Str_getLength(const char *s) {
    assert(s != NULL);
    size_t len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
};

char *Str_copy(char * restrict s1, const char * restrict s2) {
    assert(s1 != NULL && s2 != NULL);
    int index = 0;
    while (s2[index] != '\0') {
        s1[index] = s2[index++];
    }
    s1[index] = '\0';
    return s1; 
};

char *Str_concat(char * restrict s1, const char * restrict s2) {
    assert(s1 != NULL && s2 != NULL);
    int index1 = 0, index2 = 0;
    while (s1[index1] != '\0') {
        index1++;
    }
    while (s2[index2] != '\0') {
        s1[index1++] = s2[index2++];
    }
    s1[index1] = '\0';
    return s1;
};

int Str_compare(const char * s1, const char *s2) {
    int index = 0; 
    while (s1[index] == s2[index] && s1[index] != '\0' && s2[index] != '\0') {
        index++;
    } 
    if (s1[index] == '\0' && s2[index] == '\0') {
        return 0; 
    } else if (s1[index] < s2[index] || s1[index] == '\0') {
        return -1;
    } else {
        return 1;
    }
};

char *Str_search(const char *s1, const char *s2) {
    return strstr(s1, s2);
};
