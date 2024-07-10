#include "compare_sorts.h"
using namespace std;

void to_lower(char *str)
{
    while (*str) {
        *str = std::tolower(*str);
        ++str;
    }
}

void strip_punctuation(char *word)
{
    int i = 0, j = 0;
    while (word[i] != '\0') {
        if (std::isalnum(word[i]) || word[i] == '-') {
            word[j++] = word[i];
        }
        i++;
    }
    word[j] = '\0'; // Terminate the string
}

bool is_unique(char words[MAX_UNIQUE_WORDS][MAX_WORD_SIZE], int num_words, const char *word) {
    for (int i = 0; i < num_words; i++) {
        // Word not unique
        if (strcmp(words[i], word) == 0) {
            return false;
        }
    }
    // Word is unique
    return true;
}

void quicksort(int *indices, char words[MAX_UNIQUE_WORDS][MAX_WORD_SIZE], int left, int right) {
    if(left < right) {
        int pivotIndex = indices[right];
        char *pivot = words[pivotIndex];
        int i = left - 1;

        for (int j = left; j < right; j++) {
            if (strcmp(words[indices[j]], pivot) < 0) {
                i++;
                // Swap indices[i] and indices[j]
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
        // Swap indices[i + 1] and indices[right]
        int temp = indices[i + 1];
        indices[i + 1] = indices[right];
        indices[right] = temp;

        int partitionIndex = i + 1;
        quicksort(indices, words, left, partitionIndex - 1);
        quicksort(indices, words, partitionIndex + 1, right);
    }
}

void shellsort(int *indices, char words[MAX_UNIQUE_WORDS][MAX_WORD_SIZE], int size) {
    // Start with a big gap, then reduce the gap
    for (int gap = size / 2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort for this gap size.
        for (int i = gap; i < size; i++) {
            // Save indices[i] and the word it points to
            int temp = indices[i];
            char *tempWord = words[temp];
            
            // Shift earlier gap-sorted elements up until the correct location for indices[i] is found
            int j;
            for (j = i; j >= gap && strcmp(words[indices[j - gap]], tempWord) > 0; j -= gap) {
                indices[j] = indices[j - gap];
            }
            
            // Put temp (the original indices[i]) in its correct location
            indices[j] = temp;
        }
    }
}

void bubblesort(int *indices, char words[MAX_UNIQUE_WORDS][MAX_WORD_SIZE], int size)
{
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (strcmp(words[indices[j]], words[indices[j + 1]]) > 0) {
                // Swap indices[j] and indices[j + 1]
                int temp = indices[j];
                indices[j] = indices[j + 1];
                indices[j + 1] = temp;
                swapped = true;
            }
        }
        // If no elements were swapped, the array is already sorted
        if (!swapped) {
            break;
        }
    }
}

void read_words(const char *input_file, char words[MAX_UNIQUE_WORDS][MAX_WORD_SIZE], int &num_words)
{
    std::ifstream infile(input_file);
    if (!infile) {
        std::cerr << "Error opening input file.\n";
        exit(1);
    }

    char word[MAX_WORD_SIZE + 1];
    num_words = 0;

    while (infile >> word) {
        strip_punctuation(word);
        to_lower(word);
        if (word[0] != '\0' && num_words < MAX_UNIQUE_WORDS && is_unique(words, num_words, word)) {
            std::strncpy(words[num_words++], word, MAX_WORD_SIZE);
        }
    }
    infile.close();
}

void write_words(const char *output_file, char words[MAX_UNIQUE_WORDS][MAX_WORD_SIZE], int *indices, int num_words) 
{
    std::ofstream outfile(output_file);
    if (!outfile) {
        std::cerr << "Error opening output file.\n";
        exit(1);
    }

    for (int i = 0; i < num_words; ++i) {
        outfile << words[indices[i]] << '\n';
    }

    outfile.close();
}

void sort_and_measure_quicksort(char words[MAX_UNIQUE_WORDS][MAX_WORD_SIZE], int* indices, int num_words, void (*sort_func)(int *, char [MAX_UNIQUE_WORDS][MAX_WORD_SIZE], int, int), const char *sort_name) {
    //get start time
    auto start = chrono::high_resolution_clock::now();

    //Call sorting func
    sort_func(indices, words, 0, num_words - 1);

    //Get end time
    auto end = chrono::high_resolution_clock::now();

    //Calculate the duration
    chrono::duration<double> diff = end - start;

    //Print details
    cout << "Sorting with " << sort_name << " completed in " << fixed << setprecision(6) << diff.count() << " seconds." << endl;
}

void sort_and_measure_shell_bubble(char words[MAX_UNIQUE_WORDS][MAX_WORD_SIZE], int* indices, int num_words, void (*sort_func)(int *, char [MAX_UNIQUE_WORDS][MAX_WORD_SIZE], int), const char *sort_name) {
    //get start time
    auto start = chrono::high_resolution_clock::now();

    //Call sorting func
    sort_func(indices, words, num_words);

    //Get end time
    auto end = chrono::high_resolution_clock::now();

    //Calculate the duration
    chrono::duration<double> diff = end - start;

    //Print details
    cout << "Sorting with " << sort_name << " completed in " << fixed << setprecision(6) << diff.count() << " seconds." << endl;
}

int main() {
    const char *input_file = "/Users/aether/Documents/ENSF-694/ENSF-694Lab2/part1ExerciseE/input.txt"; // Change this to your input file
    char words[MAX_UNIQUE_WORDS][MAX_WORD_SIZE];
    int num_words;
    
    read_words(input_file, words, num_words);
    
    int indices[num_words];
    for (int i = 0; i < num_words; ++i) {
        indices[i] = i;
    }

    sort_and_measure_quicksort(words,indices, num_words, quicksort, "Quick Sort");
    write_words("/Users/aether/Documents/ENSF-694/ENSF-694Lab2/part1ExerciseE/output_quicksort.txt", words, indices, num_words);
    sort_and_measure_shell_bubble(words,indices, num_words, shellsort, "Shell Sort");
    write_words("//Users/aether/Documents/ENSF-694/ENSF-694Lab2/part1ExerciseE/output_shellsort.txt", words, indices, num_words);
    sort_and_measure_shell_bubble(words, indices, num_words, bubblesort, "Bubble Sort");
    write_words("/Users/aether/Documents/ENSF-694/ENSF-694Lab2/part1ExerciseE/output_bubblesort.txt", words, indices, num_words);
    return 0;
}
