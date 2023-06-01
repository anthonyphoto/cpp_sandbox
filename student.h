using namespace std;

class Student {
    public:
        Student();
        Student(string name, int id, double gpa);
        // ~Student();
        void printInfo();
        double getGpa() const;
        int getId() const;
    private:
        string name_;
        int id_;
        double gpa_;

};