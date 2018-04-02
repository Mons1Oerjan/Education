#ifndef AUTORESIZABLE_H
#define AUTORESIZABLE_H

class AutoResizable {
    protected:
        int *inner;
        int maxSize;
        int currSize;
    public:
        AutoResizable();
        ~AutoResizable();
        int getCurrSize();
        int getMaxSize();
        void add(int n);
};

#endif
