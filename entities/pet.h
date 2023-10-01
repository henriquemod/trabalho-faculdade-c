enum PetSize
{
    SMALL,
    MEDIUM,
    LARGE
};

struct Pet
{
    char name[16];
    char breed[32];
    int weight;
    enum PetSize size;
};