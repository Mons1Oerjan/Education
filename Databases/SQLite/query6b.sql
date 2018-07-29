SELECT "ID", "email", "First Name", "Last Name", "number of courses in current term" FROM students s JOIN courses c USING (ID) WHERE c."number of courses in current term" > 4;
