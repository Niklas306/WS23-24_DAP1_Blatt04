#include <cstdio>

// Gibt den größten Wert des Arrays zurück,
// der kleiner oder gleich cap ist.
// Wenn kein geeigneter Wert vorhanden ist,
// gibt die Funktion cap+1 zurück.
int capped_max(int array[], int size, int cap) {
  int output = 0;
  bool foundSomething = false;

  for (int i = 0; i < size; i++) {
    if (array[i] <= cap && array[i] > output) {
      output = array[i];
      foundSomething = true;
    }
  }

  if (foundSomething == false) {
    output = cap + 1;
  }
  return output;
}

int main() {
  char filename[1000];
  printf("Enter a filename that contains the given array:\n");
  scanf("%s", filename);

  // Die nachfolgenden acht Zeilen sollten Sie ersetzen:
  // - Lesen Sie das Array aus der Datei ein, die in filename angegeben ist
  // - Das Format der Datei ist im Moodle beschrieben
  // ========================================================================

  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    perror("Datei konnte nicht geöffnet werden: \n");
    return 1;
  }

  int size;
  fscanf(file, "%d", &size);

  int* arr = new int[size];

  for (int i = 0; i < size; ++i) {
    fscanf(file, "%d", &arr[i]);
  }

  fclose(file);

  // ========================================================================

  printf("The size of the array is %i.\n", size);
  printf("The array contains the following values:\n");
  printf("[%i", arr[0]);
  for (int i = 1; i < size; ++i) {
    printf(", %i", arr[i]);
  }
  printf("]\n");

  int cap;
  printf("Enter the value of cap:\n");
  scanf("%i", &cap);
  printf("The capped max is %i.\n", capped_max(arr, size, cap));

  delete[] arr;

  return 0;
}
