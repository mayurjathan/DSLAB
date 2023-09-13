#include<stdio.h>
#define MAX 20
typedef struct{
    int row;
    int col;
    int val;
}Sparse;
void displaySparse(Sparse* s){
    printf("index\trow\tcol\tval\n");
    for(int i=0; i<=s[0].val; i++){
        printf("%d\t%d\t%d\t%d\n", i, s[i].row, s[i].col, s[i].val);
    }
}
void transpose(Sparse* s, Sparse* t){
    t[0].row = s[0].col;
    t[0].col = s[0].row;
    t[0].val = s[0].val;

    int k=0; //non-zero element counter
    for(int i=0; i<s[0].col; i++){ //for all possible column indices
        for(int j=1; j<=s[0].val; j++){ // iterate through all present row-wise enter is
            if(i==s[j].col){           // and when index matches the entry's col index
                k++;                    // extract and insert the element'/s info
                t[k].col = s[j].row;
                t[k].row = s[j].col;
                t[k].val = s[j].val;
            }
        }
    }
}

void fastTranspose(Sparse* s, Sparse* t){
    t[0].row = s[0].col;
    t[0].col = s[0].row;
    t[0].val = s[0].val;

    int n[MAX]={}, startingPos[MAX];
    int i, j, k, pos;

    for(i=1; i<=s[0].val; i++){
        n[s[i].col]++;
    }
    startingPos[0] = 1;
    for(i=1; i<=s[0].col; i++){
        startingPos[i]= startingPos[i-1] + n[i-1];
    }

    for(i=1; i<=s[0].val; i++){
        pos = startingPos[s[i].col]++;  //get insertion position for current element's column index
        t[pos].val = s[i].val;
        t[pos].row = s[i].col;
        t[pos].col = s[i].row;
    }
}

int convertToSparse(Sparse* s, int a[][MAX], int m, int n){
    int i, j, k=0;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            if(a[i][j]!=0){
                k++;
                s[k].row = i;
                s[k].col = j;
                s[k].val = a[i][j];
            }
        }
    }
    s[0].row = m;
    s[0].col = n;
    s[0].val = k;

    return k;
}

int main(){
    Sparse s[MAX*MAX], transposed[10];
    printf("Enter order of matrix: ");
    int m, n, i, j, k=0; //k is non-zero elements counter

    //scan a matrix
    int a[MAX][MAX];
    scanf("%d %d", &m, &n);
    printf("Enter elements:\n");
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf("%d", &a[i][j]);

    convertToSparse(s, a, m, n);

    printf("Entered Matrix in Sparse Form:\n");
    displaySparse(s);
    //fast-transpose the sparse matrix and display it
    fastTranspose(s, transposed);
    printf("Transposed Matrix in Sparse Form:\n");
    displaySparse(transposed);
}
