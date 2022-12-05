#include "main.h"

using namespace std;

//Делим массив на 2 массива с элементами больше pivot'a и меньше
template <typename T>
static int partition(T arr[], int idx_start, int idx_end)
{
    int idx_pivot = 0;
    //Выбираем пивот случайным образом;
    int random = idx_start + rand() % (idx_end - idx_start);
    int pivot = arr[idx_start];
    int counter = 0, i = 0, j = 0;

    for (int k = idx_start + 1; k <= idx_end; ++k)
        if (arr[k] <= pivot)
            counter++;

    idx_pivot = counter + idx_start;

    std::swap(arr[idx_pivot], arr[idx_start]);

    i = idx_start;
    j = idx_end;

    while (i < idx_pivot && j > idx_pivot)
    {
        while (arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i < idx_pivot && j > idx_pivot)
            std::swap(arr[i], arr[j]);
    }
    return idx_pivot;
}

template <typename T>
void quickSort(T arr[], int idx_start, int idx_end)
{
    if (idx_start >= idx_end)
        return;

    int idx_pivot = partition(arr, idx_start, idx_end);

    quickSort(arr, idx_start, idx_pivot - 1);
    quickSort(arr, idx_pivot + 1, idx_end);

}

//Сортировка пузырьком
template <typename T>
void bubbleSort(T array[], int start, int end){
    T temporary;
    for(int i = start; i <= end; i++){
        for(int j = start; j <= end - i - 1; j++){
            if(array[j] > array[j + 1]){
                //меняем элементы
                temporary = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temporary;
            }
        }
    }
}

//Selection sort
template<typename T>
void selectionSort(T *array, int last) {
    int i, j, imin;
    for(i = 0; i <= last; i++) {
        imin = i;   //get index of minimum data
        for(j = i+1; j <= last; j++)
            if(array[j] < array[imin])
                imin = j;
        //placing in correct position
        swap(array[i], array[imin]);
    }
}

//вывод массива на экран
template<typename T>
void printArray(T *array, int index_last){
    for(int i = 0; i <= index_last; i++){
        cout << array[i] << " ";
    }
}


//Заполняем массив длиной 10000 случайными интами
void fullfill_Array(int *array, int index_last){
    for(int i = 0; i <= index_last; i++){
        array[i] = experimental::randint(0, 10000);
    }
}
int main() {
    for(int j = 0; j < 100; j++) {
        double start_time = clock();
        int array[10000];
        fullfill_Array(array, 9999);
        quickSort(array, 0, 9999);

        //printArray(array, 9999);

        double check_quickSort = clock();

        int array1[10000];
        fullfill_Array(array1, 9999);
        bubbleSort(array1, 0, 9999);

        //printArray(array1, 9999);

        double check_bubblesort = clock();

        int array2[10000];
        fullfill_Array(array2, 9999);
        selectionSort(array2, 9999);

        //printArray(array2, 9999);

        cout << endl;

        double stop_time = clock();

        cout << check_quickSort - start_time << " ms for quickSort, " << check_bubblesort - check_quickSort <<
             " ms for bubbleSort, " << stop_time - check_bubblesort << " ms for selectionSort" << endl;
    }
    return 0;
}
