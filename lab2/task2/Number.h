struct list{
    char d;
    struct list *next;
    struct list *prev;
};
struct Number{
    int base;
    int length;
    struct list *digit;
};
