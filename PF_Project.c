#include <stdio.h>
#include <math.h>

#define MAX 3  // It is called Memory allocation (Maximum 3 variables)

// These are 13 prototype of functions
void gaussElimination(int n, float A[MAX][MAX], float B[MAX]);
void gaussJordan(int n, float A[MAX][MAX], float B[MAX]);
void matrixTranspose(int n, float A[MAX][MAX]);
float matrixDeterminant(int n, float A[MAX][MAX]);
int matrixRank(int n, float A[MAX][MAX]);
void matrixMultiplication(int n, float A[MAX][MAX], float B[MAX][MAX]);
void matrixAddition(int n, float A[MAX][MAX], float B[MAX][MAX]);
void displayMatrix(int n, int m, float matrix[MAX][MAX]);
void displayAugmentedMatrix(int n, float aug[MAX][MAX+1]);
void inputMatrix(int n, int m, float matrix[MAX][MAX]);
void copyMatrix(int n, float dest[MAX][MAX], float src[MAX][MAX]);
void displayMenu();
void linearEquationMenu();

int main() {
    int choice, subChoice, n;
    float A[MAX][MAX] = {0}, B[MAX] = {0}, C[MAX][MAX] = {0}, D[MAX][MAX] = {0};
    float det;
    int rank;

    while (1) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("You have Enter the invalid input. Please Enter the number.\n");
            while (getchar() != '\n'); // It Clear the input from Keyboard(stdin)
            continue;
        }

        if (choice == 7) {
            printf("Thank you, Have a nice day!\n");
            break;
        }

        switch (choice) {
            case 1: // Its solve EQs through Guass Elimination and Guass Jordon Method
                linearEquationMenu();
                if (scanf("%d", &subChoice) != 1) {
                    printf("Invalid input!\n");
                    while (getchar() != '\n');
                    continue;
                }
                
                if (subChoice == 3) continue;
                
                switch (subChoice) {
                    case 1:
                        n = 2;
                        printf("\nSolving 2 equations with 2 variables\n");
                        break;
                    case 2:
                        n = 3;
                        printf("\nSolving 3 equations with 3 variables\n");
                        break;
                    default:
                        printf("Invalid choice!\n");
                        continue;
                }

                // Initializing 1 matrices by n rows and n columns and 1D array with zero
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        A[i][j] = 0;
                    }
                    B[i] = 0;
                }

                printf("\nEnter Coefficient Matrix A (%dx%d):\n", n, n);
                inputMatrix(n, n, A);

                printf("\nEnter Constant Matrix B (%dx1):\n", n);
                for (int i = 0; i < n; i++) {
                    printf("Equation %d constant: ", i + 1);
                    scanf("%f", &B[i]);
                }

                printf("\n--- SOLVING SYSTEM OF EQUATIONS ---\n");
                
                printf("\nMethod 1: Gauss Elimination\n");
                gaussElimination(n, A, B);
                
                printf("\nMethod 2: Gauss-Jordan Elimination\n");
                gaussJordan(n, A, B);
                break;

            case 2: // Matrix Transpose
                printf("\nEnter matrix size (2 or 3): ");
                if (scanf("%d", &n) != 1 || n < 2 || n > 3) {
                    printf("Invalid size! Only 2x2 and 3x3 supported.\n");
                    while (getchar() != '\n');
                    continue;
                }
                // Initialize matrix
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        A[i][j] = 0;
                    }
                }
                printf("Enter %dx%d matrix:\n", n, n);
                inputMatrix(n, n, A);
                matrixTranspose(n, A);
                break;

            case 3: // Matrix Determinant
                printf("\nEnter matrix size (2 or 3): ");
                if (scanf("%d", &n) != 1 || n < 2 || n > 3) {
                    printf("Invalid size! Only 2x2 and 3x3 supported.\n");
                    while (getchar() != '\n');
                    continue;
                }
                // Initialize matrix
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        A[i][j] = 0;
                    }
                }
                printf("Enter %dx%d matrix:\n", n, n);
                inputMatrix(n, n, A);
                printf("\nMatrix:\n");
                displayMatrix(n, n, A);
                det = matrixDeterminant(n, A);
                printf("\nDeterminant = %.4f\n", det);
                break;

            case 4: // Matrix Rank
                printf("\nEnter matrix size (2 or 3): ");
                if (scanf("%d", &n) != 1 || n < 2 || n > 3) {
                    printf("Invalid size! Only 2x2 and 3x3 supported.\n");
                    while (getchar() != '\n');
                    continue;
                }
                // Initialize matrix
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        A[i][j] = 0;
                    }
                }
                printf("Enter %dx%d matrix:\n", n, n);
                inputMatrix(n, n, A);
                printf("\nMatrix:\n");
                displayMatrix(n, n, A);
                rank = matrixRank(n, A);
                printf("\nRank = %d\n", rank);
                break;

            case 5: // Matrix Multiplication
                printf("\nEnter matrix size (2 or 3): ");
                if (scanf("%d", &n) != 1 || n < 2 || n > 3) {
                    printf("Invalid size! Only 2x2 and 3x3 supported.\n");
                    while (getchar() != '\n');
                    continue;
                }
                // Initialize matrices
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        A[i][j] = 0;
                        C[i][j] = 0;
                    }
                }
                printf("Enter first %dx%d matrix:\n", n, n);
                inputMatrix(n, n, A);
                printf("Enter second %dx%d matrix:\n", n, n);
                inputMatrix(n, n, C);
                matrixMultiplication(n, A, C);
                break;

            case 6: // This case is for Addition of  2 matrices 
                printf("\nInput the size of matrices [2 or 3]: ");
                if (scanf("%d", &n) != 1 || n < 2 || n > 3) {
                    printf("Incorrect size! Only 2 by 2 and 3 by 3 supported.\n");
                    while (getchar() != '\n');
                    continue;
                }
                // Initializing 2 matrices by n rows and n columns 
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        A[i][j] = 0;
                        C[i][j] = 0;
                    }
                }
                printf("Enter first %dx%d matrix:\n", n, n);
                inputMatrix(n, n, A);
                printf("Enter second %dx%d matrix:\n", n, n);
                inputMatrix(n, n, C);
                matrixAddition(n, A, C);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
        
        printf("\n###################################################\n");
    }

    return 0;
}
void copyMatrix(int n, float dest[MAX][MAX], float src[MAX][MAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dest[i][j] = src[i][j];
        }
    }
}

void gaussElimination(int n, float A[MAX][MAX], float B[MAX]) { // This guass elimination function
    float aug[MAX][MAX+1];

    // It create the augmented matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            aug[i][j] = A[i][j];
        }
        aug[i][n] = B[i];
    }

    printf("\nAugmented Matrix:\n");
    displayAugmentedMatrix(n, aug);

    // It is first downward elimination called forward elimination 
        for (int k = 0; k < n - 1; k++) {
            for (int i = k + 1; i < n; i++) {
                if (fabs(aug[k][k]) < 1e-10) {
                printf("Error: Division by zero encountered!\n");
                return;                   
            }
                float factor = aug[i][k] / aug[k][k];
                for (int j = k; j <= n; j++){
                aug[i][j] = aug[i][j]-factor * aug[k][j];
                }
        }
    }

    printf("\nAfter Forward Elimination:\n");
    displayAugmentedMatrix(n, aug);

    // This loop is for Back substitution
    float x[MAX];
    for (int i = n - 1; i >= 0; i--) {
        x[i] = aug[i][n];
        for (int j = i + 1; j < n; j++)
            x[i] = x[i]-aug[i][j] * x[j];
        if (fabs(aug[i][i]) < 1e-10) {
            printf("Error: No unique solution exists!\n");
            return;
        }
        x[i] = x[i]/aug[i][i];
        if (x[i]==-0.0000)
        {
            x[i]=0;
        }
        
    }

    printf("\n--- Solution (Gauss Elimination) ---\n");
    for (int i = 0; i < n; i++)
        printf("x%d = %.1f\n", i + 1, x[i]);
}

void gaussJordan(int n, float A[MAX][MAX], float B[MAX]) {
    float aug[MAX][MAX+1];

    //   Create augmented matrix same as gaussElimination
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            aug[i][j] = A[i][j];
        }
        aug[i][n] = B[i];
    }

    printf("\nAugmented Matrix:\n");
    displayAugmentedMatrix(n, aug);

    // Gauss-Jordan elimination
    for (int k = 0; k < n; k++) {
        // Find  row
        if (fabs(aug[k][k]) < 1e-10) {
            int swapRow = -1;
            for (int i = k + 1; i < n; i++) {
                if (fabs(aug[i][k]) > 1e-10) {
                    swapRow = i;
                    break;
                }
            }
            if (swapRow == -1) {
                printf("Error: No unique solution exists!\n");
                return;
            }
            // Swap rows
            for (int j = 0; j <= n; j++) {
                float temp = aug[k][j];
                aug[k][j] = aug[swapRow][j];
                aug[swapRow][j] = temp;
            }
        }

        float pivot = aug[k][k];

        // Make the pivot equal to 1
        for (int j = 0; j <= n; j++)
            aug[k][j] /= pivot;

        // Make all other rows' k-th column zero
        for (int i = 0; i < n; i++) {
            if (i != k) {
                float factor = aug[i][k];
                for (int j = 0; j <= n; j++)
                    aug[i][j] -= factor * aug[k][j];
            }
        }

        printf("\nStep %d:\n", k + 1);
        displayAugmentedMatrix(n, aug);
    }

    printf("\n--- Solution (Gauss-Jordan Method) ---\n");
    for (int i = 0; i < n; i++)
        printf("x%d = %.4f\n", i + 1, aug[i][n]);
}

void matrixTranspose(int n, float A[MAX][MAX]) {
    float transposed[MAX][MAX];
    
    // Initialize transposed matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            transposed[i][j] = 0;
        }
    }
    
    // Calculate transpose
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            transposed[j][i] = A[i][j];
        }
    }
    
    printf("\nOriginal Matrix:\n");
    displayMatrix(n, n, A);
    
    printf("\nTransposed Matrix:\n");
    displayMatrix(n, n, transposed);
}

float matrixDeterminant(int n, float A[MAX][MAX]) {
    if (n == 1) {
        return A[0][0];
    }
    else if (n == 2) {
        return A[0][0] * A[1][1] - A[0][1] * A[1][0];
    }
    else if (n == 3) {
        return A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1]) -
               A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0]) +
               A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);
    }
    return 0;
}

int matrixRank(int n, float A[MAX][MAX]) {
    float temp[MAX][MAX];
    int rank = n;
    
    // Create a copy of the matrix
    copyMatrix(n, temp, A);
    
    // Gauss elimination
    for (int k = 0; k < n; k++) {
        // Find diagonal row
        if (fabs(temp[k][k]) < 1e-10) {
            int swapRow = -1;
            for (int i = k + 1; i < n; i++) {
                if (fabs(temp[i][k]) > 1e-10) {
                    swapRow = i;
                    break;
                }
            }
            if (swapRow == -1) {
                rank--;
                continue;
            }
            // It swap the row
            for (int j = 0; j < n; j++) {
                float tempVal = temp[k][j];
                temp[k][j] = temp[swapRow][j];
                temp[swapRow][j] = tempVal; 
            }
        }
        
        // It eliminate the row below
        for (int i = k + 1; i < n; i++) {
            float factor = temp[i][k] / temp[k][k];
            for (int j = k; j < n; j++) {
                temp[i][j] -= factor * temp[k][j];
            }
        }
    }
    
    return rank;
}

void matrixMultiplication(int n, float A[MAX][MAX], float B[MAX][MAX]) {
    float result[MAX][MAX];
    
    // Initialize result matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
        }
    }
    
    // Matrix multiplication
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
    printf("\nMatrix A:\n");
    displayMatrix(n, n, A);
    
    printf("\nMatrix B:\n");
    displayMatrix(n, n, B);
    
    printf("\nResult (A × B):\n");
    displayMatrix(n, n, result);
}

void matrixAddition(int n, float A[MAX][MAX], float B[MAX][MAX]) { // It is for addition of 2 matrices
    float result[MAX][MAX];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    
    printf("\nMatrix A:\n");
    displayMatrix(n, n, A);
    
    printf("\nMatrix B:\n");
    displayMatrix(n, n, B);
    
    printf("\nResult (A + B):\n");
    displayMatrix(n, n, result);
}

void displayMatrix(int n, int m, float matrix[MAX][MAX]) { // It is for displaying matrices 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%8.1f ", matrix[i][j]);
        printf("\n");
    }
}

void displayAugmentedMatrix(int n, float aug[MAX][MAX+1]) {// It is for display augmented matrix 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
        printf("%8.1f ", aug[i][j]);
        }
        printf("|%8.1f\n", aug[i][n]);
    }
}

void inputMatrix(int n, int m, float matrix[MAX][MAX]) {  // It take input row wise
    for (int i = 0; i < n; i++) {
        printf("Row %d: ", i + 1);
        for (int j = 0; j < m; j++) {
            if (scanf("%f", &matrix[i][j]) != 1) {
                printf("Invalid input! Please enter numbers only.\n");
                while (getchar() != '\n'); // It clear the input from the stdin (Keyboard)
                j--; // This is because to re input the number 
            }
        }
    }
    return ;
}

void displayMenu() {      // This is main menu of 6 functions 
    printf("\n--- MATRIX OPERATIONS Library ---\n");
    printf("Maximum 3x3 matrices supported\n");
    printf("1. Solve Linear Equations\n");
    printf("2. Matrix Transpose\n"); 
    printf("3. Matrix Determinant\n");
    printf("4. Matrix Rank\n");
    printf("5. Matrix Multiplication\n");
    printf("6. Matrix Addition\n");
    printf("7. Exit\n");
    printf("Enter your choice (1-7): ");
}

void linearEquationMenu() {     // This the menu of EQs 
    printf("\n--- LINEAR EQUATION SOLVER ---\n");
    printf("1. Solve 2 equations of 2 variables\n");
    printf("2. Solve 3 equations of 3 variables\n");
    printf("3. return to main menu\n");
    printf("Enter what do you want (1-3): ");
}
