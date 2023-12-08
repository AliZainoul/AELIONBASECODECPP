#include <iostream>
#include <cmath>

using namespace std;


class Vector {

    private: 

        // MEMBERS
        int M_size;
        double * M_data; 

    public:
        // Constructor 0 - Default Constructor
        // Usage: Vector V => V = NULLPTR
        Vector(){
            M_data = nullptr;
            M_size = 0;
        }

        // Constructor 1 - Size Constructor
        // Usage: Vector V(10) => V = [0.0 ; 0.0 ; ... ; 0.0], size=10;
        Vector(int i){
            M_data = new double[i];
            M_size = i;
        for(int k=0;k<M_size;++k) M_data[k] = 0.0;
        }

        // Constructor 2 - Size and value Constructor
        // Usage: Vector V(2,3) => V = [3;3], size=2;
        Vector(int i, double v){
            M_data = new double[i];
            M_size = i;
        for(int k=0;k<M_size;++k) M_data[k]=v;
        }
        // Constructor 3 - List Constructor
        // Usage: Vector V = {x1,...,xn} => V = [x1; ... ;xn], size=n;
        Vector(initializer_list<double> lst){
            M_data = new double[lst.size()];
            M_size = static_cast<int>(lst.size());
            copy(lst.begin(), lst.end(), M_data); // std::copy(...)
        }

        // Constructor 4 - Copy Constructor
        // Usage: Vector V = W => V = W, size=size of  W;
        Vector(Vector const &v){
            (v.M_size==0)? M_data = nullptr : M_data = new double[v.M_size];
            M_size = v.M_size;
            for (int k=0;k<M_size;++k) M_data[k] = v.M_data[k];
        }

        // Constructor 5 - Move Constructor
        // Usage: Vector V(W) => V = W, size=size of  W;
        Vector(Vector&& v){
            M_data=v.M_data;
            M_size=v.M_size;
            v.M_size = 0;
            v.M_data = nullptr;
        }

        // Destructor
        ~Vector(){
            delete[] M_data;
        }

        // Show Function
        void show(){
        cout << "Vector's Size: "<< M_size<< endl;
            cout << " Index : ";
            cout << " [ " ;
        for(int i=0; i<M_size; i++)
            {
                cout << "  " << i+1	<< "  ";
            }
            cout << " ] " ;
            cout << endl;
            cout << " Value : ";
            cout << " [ " ;
            for(int i=0; i<M_size; i++)
            {
                cout << "  " <<M_data[i] << "  ";
            }
            cout << " ] " ;
            cout << endl;
        }

        int size() const { return M_size; }    // Return Size of the Vector

        /*Vector reset(double x) {
        for(int i=0; i<M_size; i++) M_data[i]=x;
        };*/

        double& operator[](int i){return M_data[i];} // Subscript Operator left value
        double operator[](int i) const{return M_data[i];} // Subscript Operator const

        // Assignment Operator
        Vector& operator=(Vector const &v){
        if (this != &v){
            delete[] M_data;
            M_data = new double[M_size=v.M_size];
            for(int k=0;k<M_size;++k) M_data[k]=v.M_data[k];
        }
        return *this;
        }

        // Move Assignment Operator
        Vector& operator=(Vector&& v){
            delete[] M_data;
            M_data = v.M_data;
            M_size = v.M_size;
            v.M_data = nullptr;
            v.M_size = 0;
            return *this;
        }

        // Surcharge Of Operator 'Outstream'
        friend std::ostream& operator << (std::ostream& s, const Vector& v){
            s << "Vector's size is : " << v.M_size << endl;
            for (int i = 0; i < v.M_size; i++)
                s << i+1 << "  "<< v.M_data[i]<<"  "<< endl;
            return s;
        }

        // L-infinity Norm for Vectors
        double maxnorm() const{
        double max_norm=abs(M_data[0]);
        for (int i = 1; i < M_size; i++){
                double vi = abs(M_data[i]);
                if (max_norm < vi) max_norm = vi;
            }
        return max_norm;
        };

        // L-2 Norm for Vectors
        double twonorm() const{
        double two_norm=0.0;
        for (int i = 0; i < M_size; i++) two_norm += pow(M_data[i],2);
        return sqrt(two_norm);
        };

        // Dot Operator
        double dot(const Vector& v1, const Vector& v2) {
        if (v1.M_size != v2.M_size ) cout << "Bad vector sizes in dot product." ;
        double tm = v1[0]*v2[0];
        for (int i = 1; i < v1.M_size; i++) tm += v1[i]*v2[i];
        return tm;
        }

        // Scalar-Vector Product
         Vector operator*(double scalar, const Vector& vec) {
        Vector tm(vec.M_size);
        for (int i = 0; i < vec.M_size; i++) tm[i] = scalar*vec[i];
        return tm;
        }

        // Vector-Scalar Product
         Vector operator*(const Vector& vec, double scalar) {
        Vector tm(vec.M_size);
        for (int i = 0; i < vec.M_size; i++) tm[i] = scalar*vec[i];
        return tm;
        }

        // Unary Operator "+" overload - Usage: Vector V1 = +V2;
         Vector operator+(const Vector& vec) {return vec;}

        // Unary Operator "-" overload - Usage: Vector V1 = -V2;
        Vector operator-(const Vector& vec) {
        Vector minus = vec;
        for (int i = 0; i < vec.M_size; i++) minus[i] = (-1) * vec[i];
        return minus;
        }
        // Binary Operator "+" overload - Usage: Vector V = V1+V2;
        friend Vector operator+(const Vector& v1, const Vector& v2) {
        if (v1.M_size != v2.M_size ) cout << "Bad vector sizes in Vector addition.";
        Vector sum = v1;
        sum += v2;
        return sum;
        }

        // Binary Operator "-" overload - Usage: Vector V = V1-V2;
         Vector operator-(const Vector& v1, const Vector & v2) {         // v=v1-v2
            if (v1.M_size != v2.M_size ) cout << "Bad vector sizes in Vector substraction.";
            Vector sum = v1; // It would cause problem without copy constructor
            sum -= v2;
            return sum;
        }
        // Unary Operator "+=" overload - Usage: V += W
        Vector& operator+=(const Vector& vec) {
        if (M_size != vec.M_size) cout << "Bad vector sizes in operator+=()";
        for (int i = 0; i < M_size; i++) M_data[i] += vec.M_data[i];
        return *this;
        }

        // Unary Operator "-=" overload - Usage: V -= W
        Vector& operator-=(const Vector& vec) {
        if (M_size != vec.M_size) cout << "Bad vector sizes in operator-=()";
        for (int i = 0; i < M_size; i++) M_data[i] -= vec.M_data[i];
        return *this;
        }
};


/*
  // Constructors
  Vector();                             // Constructor 0: Default Constructor
  Vector(int i);                        // Constructor 1: Size Constructor
  Vector(int i, double v);              // Constructor 2: Size-Value Constructor
  Vector(initializer_list<double> lst); // Constructor 3: List Constructor
  Vector(Vector const &v);              // Constructor 4: Copy Constructor
  Vector(Vector&& v);                   // Constructor 5: Move constructor

  // Destructors
  ~Vector();

  // void reset(double x);
  void affiche();
  int size() const;    // Return Size of the Vector

  // Norms
  double maxnorm() const;                // L-infinity norm
  double twonorm() const;                // L-2 norm

  // Operators
  Vector& operator=(Vector const &v);    // Assignment Operator
  Vector& operator=(Vector&& v);         // Move Assignment Operator
  Vector& operator+=(const Vector& vec); // Binary Operator, V += W
  Vector& operator-=(const Vector& vec); // Binary Operator, V -= W
  double& operator[](int i){return M_data[i];} // Subscript Operator left value
  double operator[](int i) const{return M_data[i];} // Subscript Operator const

  // s Functions
  friend double dot(const Vector&, const Vector&);  // Dot product
  friend Vector operator*(double, const Vector&);   // Scalar-Vector Product
  friend Vector operator*(const Vector&, double);   // Vector-Scalar Product
  friend Vector operator+(const Vector&);                 // Unary Operator, V = +W
  friend Vector operator-(const Vector&);                // Unary Operator, V = -W
  friend Vector operator+(const Vector&, const Vector&); // Binary Operator V = V1 + V2
  friend Vector operator-(const Vector&, const Vector&); // Binary Operator V = V1 - V2
  friend std::ostream& operator << (std::ostream&, const Vector&);// '<<' Overload
*/

int main()
{
	double lambda = 100;
	// Constructor 0: Default Constructor
    Vector v0;
	// Constructor 1: Size Constructor
	Vector v1(10);
	// Constructor 2: Size-Value Constructor
	Vector v2(10,5);
	// Constructor 3: List Constructor
	Vector v3={-4.3,4.5,-4.6,-4.7};
	// Constructor 4: Copy Constructor
	Vector v4 = v3;
	// Constructor 5: Move constructor
	Vector v5(v2);
	//  Vector& operator=(Vector const &v);    // Assignment Operator
	Vector v6 = v4;
	//	Vector& operator=(Vector&& v);         // Move Assignment Operator
	v0=v6;
	Vector v7(v0+=v6);
	cout << "***************" << endl;
	//cout << v1;
	v1.show();
	(v1*lambda).show();
	cout << "L2-Norm is : " << v1.twonorm() << endl;
	cout << "Linfinity-Norm is : " << v1.maxnorm() << endl;
	getchar();

	cout << "***************" << endl;
	//cout << v2;
	v2.show();
	(v2*lambda).show();
	cout << "L2-Norm is : " << v2.twonorm() << endl;
	cout << "Linfinity-Norm is : " << v2.maxnorm() << endl;
	getchar();

	cout << "***************" << endl;
	//cout << v3;
	v3.show();
	(v3*lambda).show();
	cout << "L2-Norm is : " << v3.twonorm() << endl;
	cout << "Linfinity-Norm is : " << v3.maxnorm() << endl;
	getchar();

	cout << "***************" << endl;
	//cout << v4;
	v4.show();
	(v4*lambda).show();
	cout << "L2-Norm is : " << v4.twonorm() << endl;
	cout << "Linfinity-Norm is : " << v4.maxnorm() << endl;
	getchar();

	cout << "***************" << endl;
	//cout << v5;
	v5.show();
	(v5*lambda).show();
	cout << "L2-Norm is : " << v5.twonorm() << endl;
	cout << "Linfinity-Norm is : " << v5.maxnorm() << endl;
	getchar();

	cout << "***************" << endl;
	//cout << v6;
	v6.show();
	(v6*lambda).show();
	cout << "L2-Norm is : " << v6.twonorm() << endl;
	cout << "Linfinity-Norm is : " << v6.maxnorm() << endl;
	getchar();

	cout << "***************" << endl;
	//cout << v7;
	v7.show();
	(v7*lambda).show();
	cout << "L2-Norm is : " << v7.twonorm() << endl;
	cout << "Linfinity-Norm is : " << v7.maxnorm() << endl;
	getchar();

	cout << "***************" << endl;
	//cout << v0;
	v0.show();
	(v0*lambda).show();
	cout << "L2-Norm is : " << v0.twonorm() << endl;
	cout << "Linfinity-Norm is : " << v0.maxnorm() << endl;
	getchar();

}