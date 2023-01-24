void takesAnIntPtr(int *x) {
    printf("%d", *x);
}

int main(int argc, char **argv) {

    int y = 5;
    int *ptr = &y;

    takesAnIntPtr(ptr);
    return 0;

}