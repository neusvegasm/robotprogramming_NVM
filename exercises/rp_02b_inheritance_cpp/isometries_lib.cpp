#include <iostream>
#include <cmath>
using namespace std;

using Scalar=float;

struct Vec2f {
  static constexpr int Dim=2;
  Scalar values[Dim];
  inline Vec2f& operator+=(const Vec2f& src) {
    for (int i=0; i<Dim; ++i)
      values[i]+=src.values[i];
    return *this;
  };
  inline Vec2f& operator-=(const Vec2f& src) {
    for (int i=0; i<Dim; ++i)
      values[i]-=src.values[i];
    return *this;
  };
  
  inline void fill(const Scalar v=Scalar(0)) {
    for (int i=0; i<Dim; ++i)
      values[i]=v;
  };
  
  inline Scalar dot(const Vec2f& src) const {
    Scalar acc=Scalar(0);
    for (int i=0; i<Dim; ++i)
      acc += values[i]*src.values[i];
    return acc;
  };

  inline Vec2f operator+(const Vec2f& other) const {
    Vec2f v=*this;
    v+=other;
    return v;
  }

  inline Vec2f operator-(const Vec2f& other) const {
    Vec2f v=*this;
    v-=other;
    return v;
  }
};

  
ostream& operator << (ostream& os, const Vec2f& src){
  os << "V2 [" <<&src << "] '\n' [ ";
  for (int i =0; i<Vec2f::Dim; ++i) {
    os << src.values[i] << " ";
  }
  os << " ] '\n'";
  return os;
}



struct Rotation2f {
  static constexpr int Dim=2;
  Scalar R[Dim][Dim];

  void setIdentity();

  inline void fill(const Scalar v=Scalar(0)) {
    for (int i=0; i<Dim; ++i){
        for(int j=0; j<Dim; j++){
            R[i][j] = v;
        }
    }
      
  };

  //returns the inverse (transposed)
  inline Rotation2f inverse() const {
    Rotation2f inverted;
    for (int i=0;i<Dim;i++){
      for (int j=0;j<Dim;j++){
        inverted.R[j][i] = R[i][j];
      };      
    };
    return inverted;
  }
  
  // multiplies two matrices
  inline Rotation2f operator*(const Rotation2f & other) const {
    Rotation2f result;
    result.fill();

    for ( int i=0; i<Dim; i++){
        for (int j=0; j<Dim; j++){
            for (int k=0; k<Dim; k++){
                result.R[i][j] +=  R[i][k] * other.R[k][j];
            }
        }
    }
    return result;
            
  }

  // computes the angle
  Scalar toAngle() const {
    return atan2(R[1][0],R[0][0]);
  }
  
  void setAngle(Scalar angle) {
    Scalar s=sin(angle), c=cos(angle);
    // R={ {c, -s},
    //     {s,  c}
    // }; 

    // initializer list
    R[0][0] = c;
    R[0][1] = -s;
    R[1][0] = s;
    R[1][1] = c;
  }

  // returns R*src;
  Vec2f operator*(const Vec2f& src) const{
    //TODO
    Vec2f result;

    for (int i = 0; i < Dim; i++){
        float value = 0;
        for (int j = 0; j < Vec2f::Dim; j++){
            value += R[i][j] * src.values[j];  
        }
        result.values[i] = value;
    }
    return result;
  }

  const Rotation2f& transposeInPlace() {
    for (int r=0; r<Dim; ++r) {
      for (int c=r+1; c<Dim; ++c){
        std::swap(R[r][c],R[c][r]);
      }
    }
    return *this;
  }
};

ostream& operator << (ostream& os, const Rotation2f& src){
  os << "R2 [" <<&src << "] '\n' [ ";
  for (int i =0; i<Rotation2f::Dim; ++i) {
    os << " [";
    for (int j =0; j<Rotation2f::Dim; ++j) {
        os << src.R[i][j] << " ";
    }
    os << "] ";
  }
  os << " ] '\n'";
  return os;
}


struct Isometry2f {
  static constexpr int Dim=2;
  Vec2f t;
  Rotation2f R;
  Isometry2f(){}
  Isometry2f(Scalar x, Scalar y, Scalar theta){
    // todo;
    t.values[0] = x;
    t.values[1] = y;
    R.setAngle(theta);
  }

  Isometry2f(const Vec2f& translation,
             const Rotation2f& rotation){
    // todo;
    for(int i = 0; i<Dim; i++){
      t.values[i] = translation.values[i];
      for (int j = 0; j < Dim; j++){
        R.R[i][j] = rotation.R[i][j];
      }
    }
  }

  inline void setIdentity(){
    // todo
    t.fill();
    for (int i = 0; i < Dim; i++){
        for (int j = 0; j < Dim; j++){
            if (i==j)
                R.R[i][j]=1;
            else
                R.R[i][j] = 0;
        }
    }
  }

  inline Isometry2f operator*(const Isometry2f& src) const {
    //todo
    Isometry2f result;
    result.R = R * src.R;
    result.t = t + src.t;
    return result;
  }

  inline Isometry2f inverse() const {
    // todo
    Isometry2f inverted;
    inverted.R = R.inverse();
    Vec2f tneg = t-t;
    tneg = tneg -t;
    inverted.t = inverted.R*tneg;
    return inverted;
  }


  inline Vec2f operator*(const Vec2f& src) const {
    // todo
    Vec2f result;
    result = R*src;
    result += t;
    return result;
  }
  
};


ostream& operator << (ostream& os, const Isometry2f& src){
  os << "I2 Vector [" <<&src << "] '\n' [ ";
  for (int i =0; i<Vec2f::Dim; ++i) {
    os << src.t.values[i] << " ";
  }
  os << " ] '\n'";

  os << "I2 Rotation [" <<&src << "] '\n' [ ";
  for (int i =0; i<Isometry2f::Dim; ++i) {
    os << " [";
    for (int j =0; j<Isometry2f::Dim; ++j) {
        os << src.R.R[i][j] << " ";
    }
    os << "] ";
  }
  os << " ] '\n'";
  return os;
}





int main (int argc, char** argv) {
  Vec2f v1;
  v1.fill();
  cout << v1;
  Vec2f v2=v1;
  cout << v2;
  v2.fill(0.1);
  cout << v2;
  cout << (v1-=v2);

  Rotation2f r1;
  Rotation2f r2;

  r1.R[0][0] = 2;
  r1.R[0][1] = 5;
  r1.R[1][0] = 1;
  r1.R[1][1] = 4;
  r2.R[0][0] = 1;
  r2.R[0][1] = 0;
  r2.R[1][0] = 0;
  r2.R[1][1] = 1;


  cout << r1;
  cout << r1.inverse();
  cout << r1*r2;

  // todo: write the rest to test the above functions
  // hint: comment the todoes and address them one by one
  //       after each is done add a lil test

  // at the end uncomment the following
  
  Isometry2f iso(0.1,0, 0.01);
  Isometry2f pose;
  pose.setIdentity();
  cout << pose;
  Isometry2f point;
  Isometry2f point2(v1,r1);
  point.t.values[0]=0;
  point.t.values[1]=0.1;
   
  for (int i=0; i<1000000; ++i) {
    pose=pose*iso;
  }
  
  cout << pose;

}