int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize) {
    int delInd = 0;
    int insInd = studentsSize - 1;
    int top = 0;

    int count = 0;
    int count1 = 0;

    while (count1 < studentsSize - count) {
        if (students[delInd] == sandwiches[top]) {
            delInd = (delInd + 1) % studentsSize;
            top++;
            count++;
            count1 = 0;
        }
        else {
            int k = students[delInd];
            delInd = (delInd + 1) % studentsSize;
            insInd = (insInd + 1) % studentsSize;
            students[insInd] = k;
            count1++;
        }
    }

    return studentsSize - count;
}