void reverse(char* s, int count)
{
    int len = strlen(s);
    if (count == len / 2 - 1) {
        return;
    }
    char temp = *(s + len - count - 1);
    *(s + len - count - 1) = *(s + count);
    reverse(s, count + 1);
}