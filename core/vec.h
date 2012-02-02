#ifndef VEC_H
#define VEC_H

/**
  This header file defines some simple vector operations for
  2, 3, and 4 vectors.
  **/

#include <cmath>

#define MAX(X, Y) (X) > (Y) ? (X) : (Y)
#define MIN(X, Y) (X) < (Y) ? (X) : (Y)

struct Float3
{
    Float3(float v0 = 0, float v1 = 0, float v2 = 0) : x(v0), y(v1), z(v2) { }
    Float3(float *data) { x = data[0]; y = data[1]; z = data[2]; }

    static inline Float3 zero() { return Float3(0,0,0); }
    static inline Float3 one() { return Float3(1,1,1); }

    #define VECOP_PCW(op) { x op rhs.x; y op rhs.y; z op rhs.z; return *this; }
    #define VECOP_SCA(op) { x op rhs;   y op rhs  ; z op rhs  ; return *this; }

    inline Float3& operator  = (const Float3& rhs) VECOP_PCW( =) /// equality assignment
    inline Float3& operator += (const Float3& rhs) VECOP_PCW(+=) /// piecewise addition operator
    inline Float3& operator -= (const Float3& rhs) VECOP_PCW(-=) /// piecewise subtraction operator
    inline Float3& operator *= (const Float3& rhs) VECOP_PCW(*=) /// piecewise mult operator
    inline Float3& operator /= (const Float3& rhs) VECOP_PCW(/=) /// piecewise div operator

    inline Float3  operator  + (const Float3& rhs) const { return Float3(*this) += rhs; } /// piecewise addition
    inline Float3  operator  - (const Float3& rhs) const { return Float3(*this) -= rhs; } /// piecewise subtraction
    inline Float3  operator  * (const Float3& rhs) const { return Float3(*this) *= rhs; } /// piecewise mult
    inline Float3  operator  / (const Float3& rhs) const { return Float3(*this) /= rhs; } /// piecewise div

    inline Float3& operator += (const float  rhs)  VECOP_SCA(+=) /// scalar addition operator
    inline Float3& operator -= (const float  rhs)  VECOP_SCA(-=) /// scalar subtraction operator
    inline Float3& operator *= (const float  rhs)  VECOP_SCA(*=) /// scalar multiplication operator
    inline Float3& operator /= (const float  rhs)  VECOP_SCA(/=) /// scalar division operator

    inline Float3  operator  + (const float  rhs) const { return Float3(*this) += rhs; } /// piecewise addition
    inline Float3  operator  - (const float  rhs) const { return Float3(*this) -= rhs; } /// piecewise subtraction
    inline Float3  operator  * (const float  rhs) const { return Float3(*this) *= rhs; } /// piecewise multiplication
    inline Float3  operator  / (const float  rhs) const { return Float3(*this) /= rhs; } /// piecewise multiplication

    #undef VECOP_PCW
    #undef VECOP_SCA

    inline float dot(const Float3 &rhs) const
    {
        return x * rhs.x + y * rhs.y + z * rhs.z;
    }

    inline float normalize()
    {
        float m = getMagnitude();
        x /= m, y /= m, z /= m;
        return m;
    }

    inline Float3 getNormalized() const
    {
        float m = getMagnitude();
        return Float3(x / m, y / m, z / m);
    }

    inline float getMagnitude() const
    {
        return sqrt(getMagnitude2());
    }

    inline float getMagnitude2() const
    {
        return x * x + y * y + z * z;
    }

    inline float getDistance(const Float3 &rhs) const
    {
        return sqrt(getDistance2(rhs));
    }

    inline float getDistance2(const Float3 &rhs) const
    {
        return (rhs.x - x) * (rhs.x - x) + (rhs.y - y) * (rhs.y - y) +
            (rhs.z - z) * (rhs.z - z);
    }

    inline Float3 cross(const Float3& rhs) const
    {
        return Float3(data[1] * rhs.data[2] - data[2] * rhs.data[1],
               data[2] * rhs.data[0] - data[0] * rhs.data[2],
               data[0] * rhs.data[1] - data[1] * rhs.data[0]);
    }

    /// rotate around y axis
    inline Float3 rotateY(float theta) const
    {
        return Float3(z*sinf(theta)+x*cosf(theta),
              y,
              z*cosf(theta)-x*sinf(theta));
    }

    /// rotate around x axis
    inline Float3 rotateX(float theta) const
    {
        return Float3(x,
              y*cosf(theta)-z*sinf(theta),
              y*sinf(theta)+z*cosf(theta));
    }

    inline bool operator==(const Float3 &rhs)
    {
        return (x == rhs.x && y == rhs.y && z == rhs.z);
    }

    inline bool operator!=(const Float3 &rhs)
    {
        return (x != rhs.x || y != rhs.y || z != rhs.z);
    }

    union
    {
        struct
        {
            float x, y, z;
        };
        struct
        {
            float r, g, b;
        };
        float data[3];
    };
};

inline static float dot(const Float3 &v1, const Float3 &v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

inline Float3 operator*(const float scale, const Float3 &rhs)
{
    return Float3(rhs.x * scale, rhs.y * scale, rhs.z * scale);
}

inline Float3 operator/(const float scale, const Float3 &rhs)
{
    return Float3( scale / rhs.x , scale / rhs.y , scale / rhs.z);
}

inline Float3 operator-(const Float3 &rhs)
{
    return Float3(-rhs.x, -rhs.y, -rhs.z);
}

struct Float2
{
    union
    {
        struct
        {
            float x, y;
        };
        float data[2];
    };

    inline Float2& max(float v) { x = MAX(x, v); y = MAX(y, v); return *this; }
    inline Float2& min(float v) { x = MIN(x, v); y = MIN(y, v); return *this; }

    void set(float xu, float yu) { x = xu; y = yu; }

    Float2(float v0 = 0, float v1 = 0) : x(v0), y(v1){ }
    Float2(float *data) { x = data[0]; y = data[1]; }

    static inline Float2 zero() { return Float2(0,0); }
    static inline Float2 one() { return Float2(1,1); }

    #define VECOP_PCW(op) { x op rhs.x; y op rhs.y; return *this; }
    #define VECOP_SCA(op) { x op rhs;   y op rhs  ; return *this; }

    inline Float2& operator  = (const Float2& rhs) VECOP_PCW( =) /// equality assignment
    inline Float2& operator += (const Float2& rhs) VECOP_PCW(+=) /// piecewise addition operator
    inline Float2& operator -= (const Float2& rhs) VECOP_PCW(-=) /// piecewise subtraction operator
    inline Float2& operator *= (const Float2& rhs) VECOP_PCW(*=) /// piecewise mult operator
    inline Float2& operator /= (const Float2& rhs) VECOP_PCW(/=) /// piecewise div operator

    inline Float2  operator  + (const Float2& rhs) const { return Float2(*this) += rhs; } /// piecewise addition
    inline Float2  operator  - (const Float2& rhs) const { return Float2(*this) -= rhs; } /// piecewise subtraction
    inline Float2  operator  * (const Float2& rhs) const { return Float2(*this) *= rhs; } /// piecewise mult
    inline Float2  operator  / (const Float2& rhs) const { return Float2(*this) /= rhs; } /// piecewise div

    inline Float2& operator += (const float  rhs)  VECOP_SCA(+=) /// scalar addition operator
    inline Float2& operator -= (const float  rhs)  VECOP_SCA(-=) /// scalar subtraction operator
    inline Float2& operator *= (const float  rhs)  VECOP_SCA(*=) /// scalar multiplication operator
    inline Float2& operator /= (const float  rhs)  VECOP_SCA(/=) /// scalar division operator

    inline Float2  operator  + (const float  rhs) const { return Float2(*this) += rhs; } /// piecewise addition
    inline Float2  operator  - (const float  rhs) const { return Float2(*this) -= rhs; } /// piecewise subtraction
    inline Float2  operator  * (const float  rhs) const { return Float2(*this) *= rhs; } /// piecewise multiplication
    inline Float2  operator  / (const float  rhs) const { return Float2(*this) /= rhs; } /// piecewise multiplication

    #undef VECOP_PCW
    #undef VECOP_SCA
};

inline static float dot(const Float2 &v1, const Float2 &v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

inline Float2 operator*(const float scale, const Float2 &rhs)
{
    return Float2(rhs.x * scale, rhs.y * scale);
}

inline Float2 operator/(const float scale, const Float2 &rhs)
{
    return Float2( scale / rhs.x , scale / rhs.y);
}

inline Float2 operator-(const Float2 &rhs)
{
    return Float2(-rhs.x, -rhs.y);
}

struct Float4
{
    union
    {
        struct
        {
            float x, y, z, w;
        };
        float data[4];
    };

    Float4(float v0 = 0, float v1 = 0, float v2 = 0, float v3 = 0) : x(v0), y(v1), z(v2), w(v3) { }
    Float4(float *data) { x = data[0]; y = data[1]; z = data[2];w = data[3];}

    inline Float4& max(float v) { x = MAX(x, v); y = MAX(y, v); z = MAX(z, v); z = MAX(w, v); return *this; }
    inline Float4& min(float v) { x = MIN(x, v); y = MIN(y, v); z = MIN(z, v); z = MIN(w, v); return *this; }

    void set(float xu, float yu, float zu, float wu) { x = xu; y = yu; z = zu; w = wu;}


    static inline Float4 zero() { return Float4(0,0,0,0); }
    static inline Float4 one() { return Float4(1,1,1,1); }

    #define VECOP_PCW(op) { x op rhs.x; y op rhs.y; z op rhs.z; w op rhs.w; return *this; }
    #define VECOP_SCA(op) { x op rhs;   y op rhs  ; z op rhs  ; w op rhs  ; return *this; }

    inline Float4& operator  = (const Float4& rhs) VECOP_PCW( =) /// equality assignment
    inline Float4& operator += (const Float4& rhs) VECOP_PCW(+=) /// piecewise addition operator
    inline Float4& operator -= (const Float4& rhs) VECOP_PCW(-=) /// piecewise subtraction operator
    inline Float4& operator *= (const Float4& rhs) VECOP_PCW(*=) /// piecewise mult operator
    inline Float4& operator /= (const Float4& rhs) VECOP_PCW(/=) /// piecewise div operator

    inline Float4  operator  + (const Float4& rhs) const { return Float4(*this) += rhs; } /// piecewise addition
    inline Float4  operator  - (const Float4& rhs) const { return Float4(*this) -= rhs; } /// piecewise subtraction
    inline Float4  operator  * (const Float4& rhs) const { return Float4(*this) *= rhs; } /// piecewise mult
    inline Float4  operator  / (const Float4& rhs) const { return Float4(*this) /= rhs; } /// piecewise div

    inline Float4& operator += (const float  rhs)  VECOP_SCA(+=) /// scalar addition operator
    inline Float4& operator -= (const float  rhs)  VECOP_SCA(-=) /// scalar subtraction operator
    inline Float4& operator *= (const float  rhs)  VECOP_SCA(*=) /// scalar multiplication operator
    inline Float4& operator /= (const float  rhs)  VECOP_SCA(/=) /// scalar division operator

    inline Float4  operator  + (const float  rhs) const { return Float4(*this) += rhs; } /// piecewise addition
    inline Float4  operator  - (const float  rhs) const { return Float4(*this) -= rhs; } /// piecewise subtraction
    inline Float4  operator  * (const float  rhs) const { return Float4(*this) *= rhs; } /// piecewise multiplication
    inline Float4  operator  / (const float  rhs) const { return Float4(*this) /= rhs; } /// piecewise multiplication

    #undef VECOP_PCW
    #undef VECOP_SCA
};

inline static float dot(const Float4 &v1, const Float4 &v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

inline Float4 operator*(const float scale, const Float4 &rhs)
{
    return Float4(rhs.x * scale, rhs.y * scale, rhs.z * scale, rhs.w * scale);
}

inline Float4 operator/(const float scale, const Float4 &rhs)
{
    return Float4( scale / rhs.x, scale / rhs.y, scale / rhs.z, scale / rhs.w);
}

inline Float4 operator-(const Float4 &rhs)
{
    return Float4(-rhs.x, -rhs.y, -rhs.z, -rhs.w);
}


struct Int3
{
    Int3(int v0 = 0, int v1 = 0, int v2 = 0) : x(v0), y(v1), z(v2) { }
    Int3(int *data) { x = data[0]; y = data[1]; z = data[2]; }

    static inline Int3 zero() { return Int3(0,0,0); }
    static inline Int3 one() { return Int3(1,1,1); }

    #define VECOP_PCW(op) { x op rhs.x; y op rhs.y; z op rhs.z; return *this; }
    #define VECOP_SCA(op) { x op rhs;   y op rhs  ; z op rhs  ; return *this; }

    inline Int3& operator  = (const Int3& rhs) VECOP_PCW( =) /// equality assignment
    inline Int3& operator += (const Int3& rhs) VECOP_PCW(+=) /// piecewise addition operator
    inline Int3& operator -= (const Int3& rhs) VECOP_PCW(-=) /// piecewise subtraction operator
    inline Int3& operator *= (const Int3& rhs) VECOP_PCW(*=) /// piecewise mult operator
    inline Int3& operator /= (const Int3& rhs) VECOP_PCW(/=) /// piecewise div operator

    inline Int3  operator  + (const Int3& rhs) const { return Int3(*this) += rhs; } /// piecewise addition
    inline Int3  operator  - (const Int3& rhs) const { return Int3(*this) -= rhs; } /// piecewise subtraction
    inline Int3  operator  * (const Int3& rhs) const { return Int3(*this) *= rhs; } /// piecewise mult
    inline Int3  operator  / (const Int3& rhs) const { return Int3(*this) /= rhs; } /// piecewise div

    inline Int3& operator += (const int  rhs)  VECOP_SCA(+=) /// scalar addition operator
    inline Int3& operator -= (const int  rhs)  VECOP_SCA(-=) /// scalar subtraction operator
    inline Int3& operator *= (const int  rhs)  VECOP_SCA(*=) /// scalar multiplication operator
    inline Int3& operator /= (const int  rhs)  VECOP_SCA(/=) /// scalar division operator

    inline Int3  operator  + (const int  rhs) const { return Int3(*this) += rhs; } /// piecewise addition
    inline Int3  operator  - (const int  rhs) const { return Int3(*this) -= rhs; } /// piecewise subtraction
    inline Int3  operator  * (const int  rhs) const { return Int3(*this) *= rhs; } /// piecewise multiplication
    inline Int3  operator  / (const int  rhs) const { return Int3(*this) /= rhs; } /// piecewise multiplication

    #undef VECOP_PCW
    #undef VECOP_SCA

    inline int dot(const Int3 &rhs) const
    {
        return x * rhs.x + y * rhs.y + z * rhs.z;
    }

    inline int normalize()
    {
        int m = getMagnitude();
        x /= m, y /= m, z /= m;
        return m;
    }

    inline Int3 getNormalized() const
    {
        int m = getMagnitude();
        return Int3(x / m, y / m, z / m);
    }

    inline int getMagnitude() const
    {
        return sqrt(getMagnitude2());
    }

    inline int getMagnitude2() const
    {
        return x * x + y * y + z * z;
    }

    inline int getDistance(const Int3 &rhs) const
    {
        return sqrt(getDistance2(rhs));
    }

    inline int getDistance2(const Int3 &rhs) const
    {
        return (rhs.x - x) * (rhs.x - x) + (rhs.y - y) * (rhs.y - y) +
            (rhs.z - z) * (rhs.z - z);
    }

    inline Int3 cross(const Int3& rhs) const
    {
        return Int3(data[1] * rhs.data[2] - data[2] * rhs.data[1],
               data[2] * rhs.data[0] - data[0] * rhs.data[2],
               data[0] * rhs.data[1] - data[1] * rhs.data[0]);
    }

    /// rotate around y axis
    inline Int3 rotateY(int theta) const
    {
        return Int3(z*sinf(theta)+x*cosf(theta),
              y,
              z*cosf(theta)-x*sinf(theta));
    }

    /// rotate around x axis
    inline Int3 rotateX(int theta) const
    {
        return Int3(x,
              y*cosf(theta)-z*sinf(theta),
              y*sinf(theta)+z*cosf(theta));
    }

    inline bool operator==(const Int3 &rhs)
    {
        return (x == rhs.x && y == rhs.y && z == rhs.z);
    }

    inline bool operator!=(const Int3 &rhs)
    {
        return (x != rhs.x || y != rhs.y || z != rhs.z);
    }

    union
    {
        struct
        {
            int x, y, z;
        };
        struct
        {
            int r, g, b;
        };
        int data[3];
    };
};

inline static int dot(const Int3 &v1, const Int3 &v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

inline Int3 operator*(const int scale, const Int3 &rhs)
{
    return Int3(rhs.x * scale, rhs.y * scale, rhs.z * scale);
}

inline Int3 operator/(const int scale, const Int3 &rhs)
{
    return Int3( scale / rhs.x , scale / rhs.y , scale / rhs.z);
}

inline Int3 operator-(const Int3 &rhs)
{
    return Int3(-rhs.x, -rhs.y, -rhs.z);
}

struct Int2
{
    union
    {
        struct
        {
            int x, y;
        };
        int data[2];
    };

    inline Int2& max(int v) { x = MAX(x, v); y = MAX(y, v); return *this; }
    inline Int2& min(int v) { x = MIN(x, v); y = MIN(y, v); return *this; }

    void set(int xu, int yu) { x = xu; y = yu; }

    Int2(int v0 = 0, int v1 = 0) : x(v0), y(v1){ }
    Int2(int *data) { x = data[0]; y = data[1]; }

    static inline Int2 zero() { return Int2(0,0); }
    static inline Int2 one() { return Int2(1,1); }

    #define VECOP_PCW(op) { x op rhs.x; y op rhs.y; return *this; }
    #define VECOP_SCA(op) { x op rhs;   y op rhs  ; return *this; }

    inline Int2& operator  = (const Int2& rhs) VECOP_PCW( =) /// equality assignment
    inline Int2& operator += (const Int2& rhs) VECOP_PCW(+=) /// piecewise addition operator
    inline Int2& operator -= (const Int2& rhs) VECOP_PCW(-=) /// piecewise subtraction operator
    inline Int2& operator *= (const Int2& rhs) VECOP_PCW(*=) /// piecewise mult operator
    inline Int2& operator /= (const Int2& rhs) VECOP_PCW(/=) /// piecewise div operator

    inline Int2  operator  + (const Int2& rhs) const { return Int2(*this) += rhs; } /// piecewise addition
    inline Int2  operator  - (const Int2& rhs) const { return Int2(*this) -= rhs; } /// piecewise subtraction
    inline Int2  operator  * (const Int2& rhs) const { return Int2(*this) *= rhs; } /// piecewise mult
    inline Int2  operator  / (const Int2& rhs) const { return Int2(*this) /= rhs; } /// piecewise div

    inline Int2& operator += (const int  rhs)  VECOP_SCA(+=) /// scalar addition operator
    inline Int2& operator -= (const int  rhs)  VECOP_SCA(-=) /// scalar subtraction operator
    inline Int2& operator *= (const int  rhs)  VECOP_SCA(*=) /// scalar multiplication operator
    inline Int2& operator /= (const int  rhs)  VECOP_SCA(/=) /// scalar division operator

    inline Int2  operator  + (const int  rhs) const { return Int2(*this) += rhs; } /// piecewise addition
    inline Int2  operator  - (const int  rhs) const { return Int2(*this) -= rhs; } /// piecewise subtraction
    inline Int2  operator  * (const int  rhs) const { return Int2(*this) *= rhs; } /// piecewise multiplication
    inline Int2  operator  / (const int  rhs) const { return Int2(*this) /= rhs; } /// piecewise multiplication

    #undef VECOP_PCW
    #undef VECOP_SCA
};

inline static int dot(const Int2 &v1, const Int2 &v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

inline Int2 operator*(const int scale, const Int2 &rhs)
{
    return Int2(rhs.x * scale, rhs.y * scale);
}

inline Int2 operator/(const int scale, const Int2 &rhs)
{
    return Int2( scale / rhs.x , scale / rhs.y);
}

inline Int2 operator-(const Int2 &rhs)
{
    return Int2(-rhs.x, -rhs.y);
}

struct Int4
{
    union
    {
        struct
        {
            int x, y, z, w;
        };
        int data[4];
    };

    Int4(int v0 = 0, int v1 = 0, int v2 = 0, int v3 = 0) : x(v0), y(v1), z(v2), w(v3) { }
    Int4(int *data) { x = data[0]; y = data[1]; z = data[2];w = data[3];}

    inline Int4& max(int v) { x = MAX(x, v); y = MAX(y, v); z = MAX(z, v); z = MAX(w, v); return *this; }
    inline Int4& min(int v) { x = MIN(x, v); y = MIN(y, v); z = MIN(z, v); z = MIN(w, v); return *this; }

    void set(int xu, int yu, int zu, int wu) { x = xu; y = yu; z = zu; w = wu;}


    static inline Int4 zero() { return Int4(0,0,0,0); }
    static inline Int4 one() { return Int4(1,1,1,1); }

    #define VECOP_PCW(op) { x op rhs.x; y op rhs.y; z op rhs.z; w op rhs.w; return *this; }
    #define VECOP_SCA(op) { x op rhs;   y op rhs  ; z op rhs  ; w op rhs  ; return *this; }

    inline Int4& operator  = (const Int4& rhs) VECOP_PCW( =) /// equality assignment
    inline Int4& operator += (const Int4& rhs) VECOP_PCW(+=) /// piecewise addition operator
    inline Int4& operator -= (const Int4& rhs) VECOP_PCW(-=) /// piecewise subtraction operator
    inline Int4& operator *= (const Int4& rhs) VECOP_PCW(*=) /// piecewise mult operator
    inline Int4& operator /= (const Int4& rhs) VECOP_PCW(/=) /// piecewise div operator

    inline Int4  operator  + (const Int4& rhs) const { return Int4(*this) += rhs; } /// piecewise addition
    inline Int4  operator  - (const Int4& rhs) const { return Int4(*this) -= rhs; } /// piecewise subtraction
    inline Int4  operator  * (const Int4& rhs) const { return Int4(*this) *= rhs; } /// piecewise mult
    inline Int4  operator  / (const Int4& rhs) const { return Int4(*this) /= rhs; } /// piecewise div

    inline Int4& operator += (const int  rhs)  VECOP_SCA(+=) /// scalar addition operator
    inline Int4& operator -= (const int  rhs)  VECOP_SCA(-=) /// scalar subtraction operator
    inline Int4& operator *= (const int  rhs)  VECOP_SCA(*=) /// scalar multiplication operator
    inline Int4& operator /= (const int  rhs)  VECOP_SCA(/=) /// scalar division operator

    inline Int4  operator  + (const int  rhs) const { return Int4(*this) += rhs; } /// piecewise addition
    inline Int4  operator  - (const int  rhs) const { return Int4(*this) -= rhs; } /// piecewise subtraction
    inline Int4  operator  * (const int  rhs) const { return Int4(*this) *= rhs; } /// piecewise multiplication
    inline Int4  operator  / (const int  rhs) const { return Int4(*this) /= rhs; } /// piecewise multiplication

    #undef VECOP_PCW
    #undef VECOP_SCA
};

inline static int dot(const Int4 &v1, const Int4 &v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

inline Int4 operator*(const int scale, const Int4 &rhs)
{
    return Int4(rhs.x * scale, rhs.y * scale, rhs.z * scale, rhs.w * scale);
}

inline Int4 operator/(const int scale, const Int4 &rhs)
{
    return Int4( scale / rhs.x, scale / rhs.y, scale / rhs.z, scale / rhs.w);
}

inline Int4 operator-(const Int4 &rhs)
{
    return Int4(-rhs.x, -rhs.y, -rhs.z, -rhs.w);
}

#endif // VEC_H
