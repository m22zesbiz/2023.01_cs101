#include <stdio.h>
typedef struct person {
    int id; 
    char first_name[32];
    char last_name[32];
} person_t; 
    
int main(){
    FILE* wfp = fopen("person.bin", "w+"); 
    person_t p[5] = {
        {1, "IU", "Lee"}, 
        {2, "IUU", "Lee"}, 
        {3, "IUUU", "Lee"}, 
        {4, "IUUUU", "Lee"}, 
        {5, "IUUUUU", "Lee"}, 
    }; 
    for (int i = 0; i < 5; i++) {
        fwrite(p+i, sizeof(person_t), 1, wfp); 
    }
    fclose(wfp); 
    
    FILE* rfp = fopen("person.bin", "r"); 
    int i = 0; 
    person_t tmp; 
    while (fread(&tmp, sizeof(person_t), 1, rfp)) {
        fprintf(stdout, "[%d] %d: %s %s\n", i, tmp.id, tmp.first_name, tmp.last_name); 
        i++;
    }
}
