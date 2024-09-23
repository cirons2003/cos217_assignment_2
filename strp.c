#include "str.h";

size_t Str_getLength(const char *s) {
    assert(s != NULL);
    const char *startp = *endp = s;
    while (endp* != '/0') {
        endp++;
    }
    return (size_t)(endp - startp);
};

char *Str_copy(char *s1, const char *s2) {
    assert(s1 != NULL && s2 != NULL);
    const char *s1p = s1, *s2p = s2;
    while (*s2p != '\0') {
        *s1p++ = *s2p++;
    }
    *s1p = '\0';
    return s1;
}

char *Str_concat(char * s1, const char *s2) {
    assert(s1 != NULL && s2 != NULL);
    const char *s1p = s1, *s2p = s2;
    while (s1p* != '\0') {
        s1p++;
    }
    while (s2p* != '\0') {
        *s1p++ = *s2p++;
    }
    *s1p = '\0';
    return s1;
}

int Str_compare(const char *s1, const char *s2) {
    assert(s1 != NULL && s2 != NULL);
    while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0') {
        s1++;
        s2++;
    }
    if (*s1 == '\0' && *s2 == '\0') {
        return 0;
    } else if (*s1 < *s2 || *s1 == '\0') {
        return -1;
    } else {
        return 1;
    }

}

char *Str_search(const char *s1, const char *s2) {
    return strstr(s1, s2);
};
