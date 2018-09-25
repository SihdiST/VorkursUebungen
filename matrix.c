#include <stdio.h>
#include "matrix.h"



IntMatrix *IntMatrix_new(int n){
    IntMatrix* create = malloc(sizeof(IntMatrix));
    create.data = malloc(n*n*sizeof(int));
    create.size_m = n;
    return &create;
}


void  IntMatrix_delete(IntMatrix *m){
    free(m->data);
    free(m);

}

void  IntMatrix_print(IntMatrix *m){
    for(int i = 0; i < m->size_m * m->size_m; i++){
       printf("%i ", m->data[i]);
       if((i+1) % m->size_m == 0){
        printf("\n");
       }
    }
}
void  IntMatrix_id(IntMatrix *m){
    int m_size_f = *m->size_m;
    for(int i = 0; i < m_size_f * m_size_f; i ++){
        if(i % (m_size_f+1) == 0){
            m->data[i] = 1;
        }
        else{
            m->data[i] = 0;
        }

    }
}
int  IntMatrix_get(IntMatrix *m, int x, int y){
    //user weiss, dass mit 0 anfaengt
    return m->data[m->size*x+y];
}
void  IntMatrix_set(IntMatrix *m, int x, int y, int value){
    m->data[m->size*x+y] = value;
}
