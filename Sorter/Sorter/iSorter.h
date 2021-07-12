class iSorter {
public:
    virtual void sort(float*, int) = 0;
    virtual const char* name() const = 0;
};

iSorter* CreateSorter(int);
int noOfSorters();