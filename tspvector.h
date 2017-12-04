#ifndef __TSP_VECTOR__H_
    #define __TSP_VECTOR__H_               // Types are MCU dependent
    #include <stdio.h>                     // Console IO
    #include <math.h>                      // Maths
    #include <string.h>                    // Memory move and copy
    #include <stdarg.h>                    // Variable arguments notes
    #define TSP_NUM float                  // General type for floating point number
    #define TSP_STR unsigned char          // General type for strings storage in vector names
    #define TSP_BUL unsigned char          // General type for representing booleans
    #define TSP_MSG_LEN 200                // General note length. Also used for internal messages
    #define TSP_ROUND roundf               // General macro for processing rounding
    #define TSP_TRUNC truncf               // General macro for processing truncate
    #define TSP_FLOOR floorf               // General macro for processing floor
    #define TSP_CEIL  ceilf                // General macro for processing ceiling
    #define TSP_ABS   fabs                 // General macro for processing absolute
    #define TSP_PI 3.1415926535897931

    static TSP_STR msgBuffer[TSP_MSG_LEN] = {0};
    static TSP_STR tmpBuffer[TSP_MSG_LEN] = {0};

    typedef class Vec
    {
      private:
        TSP_NUM X;
        TSP_NUM Y;
        TSP_NUM Z;
        TSP_STR   *Name;
        void      *User;
        class Vec *Next;
      protected:
        void          setError(const char *form, ...) const;
      public:
        friend Vec        operator+ (Vec&, Vec&);
        friend Vec        operator+ (Vec&, TSP_NUM);
        friend Vec        operator- (Vec&, Vec&);
        friend Vec        operator- (Vec&, TSP_NUM);
        friend void       operator+=(Vec&, Vec&);
        friend void       operator+=(Vec&, TSP_NUM);
        friend void       operator-=(Vec&, Vec&);
        friend void       operator-=(Vec&, TSP_NUM);
        friend Vec        operator^ (Vec&, Vec&);
        friend void       operator^=(Vec&, Vec&);
        friend TSP_NUM    operator* (Vec&, Vec&);
        friend Vec        operator* (TSP_NUM , Vec&);
        friend Vec        operator* (Vec&, TSP_NUM);
        friend void       operator*=(Vec&, TSP_NUM);
        friend void       operator*=(Vec&, Vec&);
        friend Vec        operator/ (Vec&, TSP_NUM);
        friend Vec        operator/ (Vec&, Vec&);
        friend void       operator/=(Vec&, TSP_NUM);
        friend TSP_BUL    operator==(Vec&, Vec&);
        friend TSP_BUL    operator!=(Vec&, Vec&);
        friend TSP_BUL    operator>=(Vec&, Vec&);
        friend TSP_BUL    operator<=(Vec&, Vec&);
        friend TSP_BUL    operator> (Vec&, Vec&);
        friend TSP_BUL    operator< (Vec&, Vec&);
        friend class Vec  operator% (Vec&, Vec&);
        friend class Vec  operator% (Vec&, TSP_NUM);
        friend class Vec  operator% (TSP_NUM, Vec&);
        friend void       operator%=(Vec&, Vec&);
        friend void       operator%=(Vec&, TSP_NUM);
        friend class Vec  operator++(Vec&, int);
        friend class Vec  operator--(Vec&, int);
        friend class Vec& operator++(Vec&);
        friend class Vec& operator--(Vec&);
        void            clrError(){ memset (msgBuffer, 0, TSP_MSG_LEN); }
        TSP_STR        *getError(){ return (msgBuffer); }
        TSP_BUL         hasError(){ return (msgBuffer[0] != '\0'); }
        TSP_BUL         isZero(void) const;
        TSP_BUL         isCollinear (const Vec *b) const;
        TSP_BUL         isCollinear (const Vec &b) const;
        TSP_BUL         isOrthogonal(const Vec *b) const;
        TSP_BUL         isOrthogonal(const Vec &b) const;
        TSP_BUL         isCoplanar(const Vec &a, const Vec &b) const;
        TSP_BUL         isCoplanar(const Vec *a, const Vec *b) const;
        TSP_BUL         isCoplanar(const Vec *a, const Vec &b) const;
        TSP_BUL         isCoplanar(const Vec &a, const Vec *b) const;
        TSP_STR       *getString(const char * const fnum) const;
        TSP_NUM        getDistance(const Vec *b) const;
        TSP_NUM        getDistance(const Vec &b) const;
        TSP_NUM        getDistance(void) const;
        class Vec&        Direction(const Vec *b);
        class Vec&        Direction(const Vec &b);
        class Vec&        Direction(void);
        class Vec      getDirection(const Vec *b) const;
        class Vec      getDirection(const Vec &b) const;
        class Vec      getDirection(void) const;
        TSP_NUM        getX(void) const { return X; };
        TSP_NUM        getY(void) const { return Y; };
        TSP_NUM        getZ(void) const { return Z; };
        void          *getUser(void) const { return User; };
        TSP_STR       *getName(void) const { return Name; };
        class Vec     *getNext(void) const { return Next; };
        class Vec&     setX(TSP_NUM x){ X = x; return *this; };
        class Vec&     setY(TSP_NUM y){ Y = y; return *this; };
        class Vec&     setZ(TSP_NUM z){ Z = z; return *this; };
        class Vec&     setUser(void *pUser){ User = pUser; return *this; };
        class Vec&     setName(const void *pName){ Name = (TSP_STR*)pName; return *this; };
        class Vec&     setNext(const Vec *pNext){ Next = (class Vec *)pNext; return *this; };
        TSP_NUM        getAngleDeg(const  Vec *b) const;
        TSP_NUM        getAngleDeg(const  Vec &b) const;
        TSP_NUM        getAngleRad(const  Vec *b) const;
        TSP_NUM        getAngleRad(const  Vec &b) const;
        TSP_NUM        getAreaTriangle(const Vec *b) const;
        TSP_NUM        getAreaTriangle(const Vec &b) const;
        TSP_NUM        getAreaParallelogram(const Vec *b) const;
        TSP_NUM        getAreaParallelogram(const Vec &b) const;
        TSP_NUM        getVolumeTetrahedron(const Vec &b, const Vec &c) const;
        TSP_NUM        getVolumeTetrahedron(const Vec *b, const Vec *c) const;
        TSP_NUM        getVolumeTetrahedron(const Vec *b, const Vec &c) const;
        TSP_NUM        getVolumeTetrahedron(const Vec &b, const Vec *c) const;
        TSP_NUM        getVolumeParallelepiped(const Vec &b, const Vec &c) const;
        TSP_NUM        getVolumeParallelepiped(const Vec *b, const Vec *c) const;
        TSP_NUM        getVolumeParallelepiped(const Vec *b, const Vec &c) const;
        TSP_NUM        getVolumeParallelepiped(const Vec &b, const Vec *c) const;
        class Vec&        Center(const Vec *b);
        class Vec&        Center(const Vec &b);
        class Vec&        Center(TSP_NUM    b);
        class Vec      getCenter(const Vec *b) const;
        class Vec      getCenter(const Vec &b) const;
        class Vec      getCenter(TSP_NUM    b) const;
        class Vec&        Round(void){ X = TSP_ROUND(X); Y = TSP_ROUND(Y); Z = TSP_ROUND(Z); return *this; };
        class Vec      getRound(void) const;
        class Vec&        RoundDigit(unsigned int d);
        class Vec      getRoundDigit(unsigned int d) const;
        class Vec&        Trunc(void){ X = TSP_TRUNC(X); Y = TSP_TRUNC(Y); Z = TSP_TRUNC(Z);return *this; };
        class Vec      getTrunc(void) const;
        class Vec&        Floor(void){ X = TSP_FLOOR(X); Y = TSP_FLOOR(Y); Z = TSP_FLOOR(Z);return *this; };
        class Vec      getFloor(void) const;
        class Vec&        Ceil(void){ X = ceilf(X); Y = ceilf(Y); Z = ceilf(Z); return *this; };
        class Vec      getCeil(void) const;
        class Vec&        Project(const Vec *b);
        class Vec&        Project(const Vec &b);
        class Vec      getProject(const Vec *b) const;
        class Vec      getProject(const Vec &b) const;
        class Vec&        Add(const Vec *b);
        class Vec&        Add(const Vec &b);
        class Vec&        Add(TSP_NUM x);
        class Vec&        Add(TSP_NUM x, TSP_NUM y);
        class Vec&        Add(TSP_NUM x, TSP_NUM y, TSP_NUM z);
        class Vec      getAdd(const Vec *b) const;
        class Vec      getAdd(const Vec &b) const;
        class Vec      getAdd(TSP_NUM x) const;
        class Vec      getAdd(TSP_NUM x, TSP_NUM y) const;
        class Vec      getAdd(TSP_NUM x, TSP_NUM y, TSP_NUM z) const;
        class Vec&        Sub(const Vec *b);
        class Vec&        Sub(const Vec &b);
        class Vec&        Sub(TSP_NUM x);
        class Vec&        Sub(TSP_NUM x, TSP_NUM y);
        class Vec&        Sub(TSP_NUM x, TSP_NUM y, TSP_NUM z);
        class Vec      getSub(const Vec *b) const;
        class Vec      getSub(const Vec &b) const;
        class Vec      getSub(TSP_NUM x) const;
        class Vec      getSub(TSP_NUM x, TSP_NUM y) const;
        class Vec      getSub(TSP_NUM x, TSP_NUM y, TSP_NUM z) const;
        TSP_NUM        getCosine(TSP_STR) const;
        class Vec&        Neg(void);
        class Vec      getNeg(void) const;
        class Vec&        Mul(TSP_NUM n);
        class Vec      getMul(TSP_NUM n) const;
        class Vec&        Div(TSP_NUM n);
        class Vec&        Div(const Vec &b);
        class Vec&        Div(const Vec *b);
        class Vec      getDiv(TSP_NUM n) const;
        class Vec      getDiv(const Vec &b) const;
        class Vec      getDiv(const Vec *b) const;
        TSP_NUM        getMixed(const Vec &b, const Vec &c) const;
        TSP_NUM        getMixed(const Vec *b, const Vec *c) const;
        TSP_NUM        getMixed(const Vec *b, const Vec &c) const;
        TSP_NUM        getMixed(const Vec &b, const Vec *c) const;
        class Vec&        CrossTriple(const Vec &b, const Vec &c);
        class Vec&        CrossTriple(const Vec *b, const Vec *c);
        class Vec&        CrossTriple(const Vec *b, const Vec &c);
        class Vec&        CrossTriple(const Vec &b, const Vec *c);
        class Vec      getCrossTriple(const Vec &b, const Vec &c) const;
        class Vec      getCrossTriple(const Vec *b, const Vec *c) const;
        class Vec      getCrossTriple(const Vec *b, const Vec &c) const;
        class Vec      getCrossTriple(const Vec &b, const Vec *c) const;
        class Vec&        Set(const Vec &b);
        class Vec&        Set(const Vec *b);
        class Vec&        Set(TSP_NUM x, TSP_NUM y, TSP_NUM z);
        class Vec&        Set(TSP_NUM x, TSP_NUM y);
        class Vec&        Set(TSP_NUM x);
        class Vec&        Set(void);
        class Vec&        Offset(const Vec &Dir, TSP_NUM n);
        class Vec&        Offset(const Vec *Dir, TSP_NUM n);
        class Vec      getOffset(const Vec &Dir, TSP_NUM n) const;
        class Vec      getOffset(const Vec *Dir, TSP_NUM n) const;
        class Vec&        Cross(const Vec *b);
        class Vec&        Cross(const Vec &b);
        class Vec      getCross(const Vec *b) const;
        class Vec      getCross(const Vec &b) const;
        TSP_NUM        getDot(const Vec *b) const;
        TSP_NUM        getDot(const Vec &b) const;
        class Vec&        RollR(void);
        class Vec      getRollR(void) const;
        class Vec&        RollL(void);
        class Vec      getRollL(void) const;
        class Vec&        ShiftR(void);
        class Vec      getShiftR(void) const;
        class Vec&        ShiftL(void);
        class Vec      getShiftL(void) const;
        class Vec&        Swap(const void* Comp);
        class Vec      getSwap(const void* Comp) const;
        class Vec&        Print(void);
        class Vec&        Print(FILE *f);
        class Vec&        Print(TSP_STR *s);
        class Vec&        PrintTrajectory(void);
                          Vec(const Vec &src);
                          Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z, const void *name, void *user, class Vec *next);
                          Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z, const void *name, class Vec *next);
                          Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z, const void *name);
                          Vec(const void *name);
                          Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z);
                          Vec(TSP_NUM x, TSP_NUM y);
                          Vec(TSP_NUM x);
                          Vec(void);
                         ~Vec(void){};
    } cVec;

    Vec::Vec()
    {
      setX(0.0); setY(0.0); setZ(0.0); setUser(NULL); setName(NULL); setNext(NULL);
    }

    Vec::Vec(TSP_NUM x)
    {
      setX(x); setY(0.0); setZ(0.0); setUser(NULL); setName(NULL); setNext(NULL);
    }

    Vec::Vec(TSP_NUM x, TSP_NUM y)
    {
      setX(x); setY(y); setZ(0.0); setUser(NULL); setName(NULL); setNext(NULL);
    }

    Vec::Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z)
    {
      setX(x); setY(y); setZ(z); setUser(NULL); setName(NULL); setNext(NULL);
    }

    Vec::Vec(const Vec &src)
    {
      setX(src.getX()); setY(src.getY()); setZ(src.getZ());
      setUser(NULL); setName(NULL); setNext(NULL);
    }

    Vec::Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z, const void *name, void *user, class Vec *next)
    {
      setX(x); setY(y); setZ(z); setUser(user);
      setName((const TSP_STR*)name); setNext(next);
    }

    Vec::Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z, const void *name, class Vec *next)
    {
      setX(x); setY(y); setZ(z); setUser(NULL);
      setName((const TSP_STR*)name); setNext(next);
    }
    Vec::Vec(const void *name)
    {
      setX(0.0); setY(0.0); setZ(0.0); setUser(NULL);
      setName((const TSP_STR*)name); setNext(NULL);
    }

    Vec::Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z, const void *name)
    {
      setX(x); setY(y); setZ(z); setUser(NULL);
      setName((const TSP_STR*)name); setNext(NULL);
    }

    void Vec::setError(const char *form, ...) const
    {
      va_list args;
      va_start (args, form);
      vsprintf((char*)msgBuffer, form, args);
      va_end(args);
    }

    TSP_STR* Vec::getString(const char * const fnum) const
    {
      TSP_STR tmpFormat[TSP_MSG_LEN] = {0}; strcpy((char *)tmpBuffer, "{%s,%s,%s}");
      sprintf((char*)tmpFormat,(const char* const)tmpBuffer,fnum,fnum,fnum);
      sprintf((char*)tmpBuffer,(const char* const)tmpFormat,X,Y,Z); return tmpBuffer;
    }

    Vec& Vec::Print(FILE *f)
    {
      if(f == NULL){ setError("ERR: Print(file*): Argument is null"); }
      char *nam = (char *)getName(); nam = (char *)((nam == NULL) ? "" : nam);
        fprintf(f,"\nVec %p > %p --> %s, %p\nXYZ = { %15.8f, %15.8f, %15.8f }",
           (void*)this,(void*)getNext(),nam,(void*)getUser(),getX(),getY(),getZ());
      return *this;
    }

    Vec& Vec::Print(void)
    {
      char *nam = (char *)getName(); nam = (char *)((nam == NULL) ? "" : nam);
      fprintf(stdout,"\nVec %p > %p --> %s, %p\nXYZ = { %15.8f, %15.8f, %15.8f }",
         (void*)this,(void*)getNext(),nam,(void*)getUser(),getX(),getY(),getZ());
      return *this;
    }

    Vec& Vec::Print(TSP_STR *s)
    {
      if(s == NULL){ setError("ERR: Print(string*): Argument is null"); }
      char *nam = (char *)getName(); nam = (char *)((nam == NULL) ? "" : nam);
      sprintf((char*)s,"\nVec %p > %p --> %s, %p\nXYZ = { %15.8f, %15.8f, %15.8f }",
         (void*)this,(void*)getNext(),nam,(void*)getUser(),getX(),getY(),getZ());
      return *this;
    }

    Vec& Vec::PrintTrajectory(void)
    {
      cVec *nx = this;
      while(nx != NULL)
      {
        nx->Print();
        nx = nx->getNext();
      }
      return *this;
    }

    TSP_BUL Vec::isZero(void) const { return (X==0 && Y==0 && Z==0); }

    TSP_BUL Vec::isOrthogonal(const Vec *b) const
    {
      if(b == NULL){ setError("ERR: isOrthogonal(vec*): Argument is null"); return 0; }
      return (getDot(b) == 0);
    }

    TSP_BUL Vec::isOrthogonal(const Vec &b) const { return (getDot(b) == 0); }

    TSP_BUL Vec::isCollinear(const Vec &b) const
    {
      TSP_NUM x = getX() / b.getX();
      TSP_NUM y = getY() / b.getY();
      TSP_NUM z = getZ() / b.getZ();
      return (x == y && y == z && z == x);
    }

    TSP_BUL Vec::isCollinear(const Vec *b) const
    {
      if(b == NULL){ setError("ERR: isCollinear(vec*): Argument is null"); return 0; }
      return isCollinear(*b);
    }

    TSP_NUM Vec::getDistance(void) const
    {
      TSP_NUM x = getX();
      TSP_NUM y = getY();
      TSP_NUM z = getZ();
      return sqrt(x*x + y*y + z*z);
    }

    TSP_NUM Vec::getDistance(const Vec &b) const
    {
      TSP_NUM x = getX() - b.getX();
      TSP_NUM y = getY() - b.getY();
      TSP_NUM z = getZ() - b.getZ();
      return sqrt(x*x + y*y + z*z);
    }

    TSP_NUM Vec::getDistance(const Vec *b) const
    {
      if(b == NULL){ return getDistance(); }
      return getDistance(*b);
    }

    Vec& Vec::Direction(void)
    {
      TSP_NUM dst = getDistance();
      if(dst == 0){ setError("ERR: Direction(void): Base module is zero"); return *this; }
      setX(getX() / dst);
      setY(getY() / dst);
      setZ(getZ() / dst);
      return *this;
    }

    Vec& Vec::Direction(const Vec &b)
    {
      TSP_NUM dst = getDistance(&b);
      if(dst == 0){ setError("ERR: Direction(vec&): Base module is zero"); return *this; }
      setX((getX() - b.getX()) / dst);
      setY((getY() - b.getY()) / dst);
      setZ((getZ() - b.getZ()) / dst);
      return *this;
    }

    Vec& Vec::Direction(const Vec *b)
    {
      if(b == NULL){ return Direction(); }
      Direction(*b); return *this;
    }

    Vec Vec::getDirection(void) const
    {
      cVec v = Vec();
      TSP_NUM dst = getDistance();
      if(dst == 0){ setError("ERR: getDirection(void): Base module is zero"); return v; }
      v.Set(this).Direction(); return v;
    }

    Vec Vec::getDirection(const Vec &b) const
    {
      cVec v = Vec();
      TSP_NUM dst = getDistance(&b);
      if  (dst == 0){ setError("ERR: getDirection(vec&): Argument module is zero"); return v; }
      v.Set(this).Direction(b); return v;
    }

    Vec Vec::getDirection(const Vec *b) const
    {
      if(b == NULL){ return getDirection(); }
      return getDirection(*b);
    }

    Vec operator^(Vec &a, Vec &b){ return a.getCross(b); }

    TSP_NUM operator*(Vec &a, Vec &b){ return a.getDot(b); }

    Vec operator+(Vec &a, Vec &b){ cVec v; v.Set(a).Add(b); return v; }

    Vec operator+(Vec &a, TSP_NUM n){ cVec v; v.Set(a).Add(n); return v; }

    Vec operator-(Vec &a, Vec &b){ cVec v; v.Set(a).Sub(b); return v; }

    Vec operator-(Vec &a, TSP_NUM n){ cVec v; v.Set(a).Sub(n); return v; }

    void operator+=(Vec &a, TSP_NUM n){ a.setX(a.getX() + n); }

    void operator+=(Vec &a, Vec &b){ a.Add(b); }

    void operator^=(Vec &a, Vec &b){ a.Cross(b); }

    void operator*=(Vec &a, Vec &b){ a.Mul(a.getDot(b)); }

    void operator-=(Vec &a, TSP_NUM n){ a.setX(a.getX() - n); }

    void operator-=(Vec &a, Vec &b){ a.Sub(b); }

    Vec operator*(TSP_NUM n, Vec &b){ return Vec(n * b.getX(), n * b.getY(), n * b.getZ()); }

    Vec operator*(Vec &b, TSP_NUM n){ return Vec(n * b.getX(), n * b.getY(), n * b.getZ()); }

    Vec operator/(Vec &b, TSP_NUM n)
    {
      cVec v = Vec();
      if(n == 0){ v.setError("ERR: operator/(vec&,num): Divide by zero"); return v; }
      v.Set(b.getX() / n, b.getY() / n, b.getZ() / n); return v;
    }

    Vec operator/(Vec &a, Vec &b){ cVec v = Vec(); v.Set(a).Div(b); return v; }

    void operator*=(Vec &a, TSP_NUM n){ a.Mul(n); }

    void operator/=(Vec &a, TSP_NUM n)
    {
      if(n == 0){ a.setError("ERR: oerator(/=): Divide by zero"); return; }
      a.Div(n);
    }

    TSP_BUL operator==(Vec &a, Vec &b)
    {
      return ((a.getX() == b.getX()) &&
              (a.getY() == b.getY()) &&
              (a.getZ() == b.getZ()));
    }

    TSP_BUL operator!=(Vec &a, Vec &b){ return !(a == b); }

    TSP_BUL operator>=(Vec &a, Vec &b){ return (a.getDistance() >= b.getDistance()); }

    TSP_BUL operator<=(Vec &a, Vec &b){ return (a.getDistance() <= b.getDistance()); }

    TSP_BUL operator>(Vec &a, Vec &b){ return (a.getDistance() > b.getDistance()); }

    TSP_BUL operator<(Vec &a, Vec &b){ return (a.getDistance() < b.getDistance()); }

    Vec operator++(Vec &b, int a){ cVec dr = b.getDirection(); b.Add(dr); dr.Sub(b).Neg(); return dr; }

    Vec operator--(Vec &b, int a){ cVec dr = b.getDirection(); b.Sub(dr); dr.Add(b); return dr; }

    Vec& operator++(Vec &b){ cVec dr = b.getDirection(); b.Add(dr); return b; }

    Vec& operator--(Vec &b){ cVec dr = b.getDirection(); b.Sub(dr); return b; }

    TSP_NUM Vec::getAngleRad(const Vec *b) const
    {
      if(b == NULL){ setError("ERR: getAngleRad(vec*): Argument is null"); return 0; }
      TSP_NUM dot = getDot(b);
      TSP_NUM abd = getDistance();
      TSP_NUM avd = b->getDistance();
      if(abd == 0){ setError("ERR: getAngleRad(vec*): Base module is zero"); return 0; }
      if(avd == 0){ setError("ERR: getAngleRad(vec*): Argument module is zero"); return 0; }
      return acos(dot / ( abd * avd ));
    }

    TSP_NUM Vec::getAngleRad(const Vec &b) const
    {
      TSP_NUM dot = getDot(&b);
      TSP_NUM abd = getDistance();
      TSP_NUM avd = b.getDistance();
      if(abd == 0){ setError("ERR: getAngleRad(vec*): Base module is zero"); return 0; }
      if(avd == 0){ setError("ERR: getAngleRad(vec*): Argument module is zero"); return 0; }
      return acos(dot / ( abd * avd ));
    }

    TSP_NUM Vec::getAngleDeg(const Vec &b) const { return ( getAngleRad(&b) * ( 180 / TSP_PI)); }

    TSP_NUM Vec::getAngleDeg(const Vec *b) const
    {
      if(b == NULL){ setError("ERR: getAngleDeg(vec*): Argument is null"); return 0; }
      return ( getAngleRad(b) * ( 180 / TSP_PI));
    }

    Vec& Vec::Project(const Vec &b)
    {
      TSP_NUM bcx = b.getX();
      TSP_NUM bcy = b.getY();
      TSP_NUM bcz = b.getZ();
      TSP_NUM dst2 = bcx*bcx + bcy*bcy + bcz*bcz;
      if(dst2 == 0){ setError("ERR: Project(vec&): Argument module is zero"); return *this; }
      TSP_NUM dot = getDot(b) / dst2;
      Set(dot*bcx, dot*bcy, dot*bcz);
      return *this;
    }

    Vec& Vec::Project(const Vec *b)
    {
      if(b == NULL){ setError("ERR: getAngleDeg(vec*): Argument is null"); return *this; }
      Project(*b); return *this;
    }

    Vec Vec::getProject(const Vec &b) const { cVec v = Vec(); v.Set(this).Project(b); return v; }

    Vec Vec::getProject(const Vec *b) const
    {
      if(b == NULL){ setError("ERR: getProject(vec*): Argument is null"); return Vec();}
      return getProject(*b);
    }

    Vec& Vec::Cross(const Vec &b)
    {
      Set((getY() * b.getZ()) - (getZ() * b.getY()),
          (getZ() * b.getX()) - (getX() * b.getZ()),
          (getX() * b.getY()) - (getY() * b.getX()));
      return *this;
    }

    Vec& Vec::Cross(const Vec *b)
    {
      if(b == NULL){ setError("ERR: Cross(vec*): Argument is null"); return *this; }
      Cross(*b); return *this;
    }

    Vec Vec::getCross(const Vec *b) const
    {
      cVec v = Vec();
      if(b == NULL){ setError("ERR: getCross(vec*): Argument is null"); return v; }
      v.Set(this).Cross(b); return v;
    }

    Vec Vec::getCross(const Vec &b) const
    {
      cVec v = Vec(); v.Set(this).Cross(b); return v;
    }

    Vec& Vec::CrossTriple(const Vec &b, const Vec &c)
    {
      TSP_NUM ac = getDot(c);
      TSP_NUM ab = getDot(b);
      Set((ac * b.getX()) - (ab * c.getX()),
          (ac * b.getY()) - (ab * c.getY()),
          (ac * b.getZ()) - (ab * c.getZ()));
      return *this;
    }

    Vec& Vec::CrossTriple(const Vec *b, const Vec *c)
    {
      if(b == NULL){ setError("ERR: CrossTriple(vec*, vec*): First argument module is null"); return *this; }
      if(c == NULL){ setError("ERR: CrossTriple(vec*, vec*): Second argument module is null"); return *this; }
      CrossTriple(*b,*c); return *this;
    }
    Vec& Vec::CrossTriple(const Vec *b, const Vec &c)
    {
      if(b == NULL){ setError("ERR: CrossTriple(vec&): First argument is null"); return *this; }
      CrossTriple(*b,c); return *this;
    }

    Vec& Vec::CrossTriple(const Vec &b, const Vec *c)
    {
      if(c == NULL){ setError("ERR: CrossTriple(vec&): Second argument is null"); return *this; }
      CrossTriple(b,*c); return *this;
    }

    Vec Vec::getCrossTriple(const Vec &b, const Vec &c) const
      { cVec v = Vec().Set(this).CrossTriple(b,c); return v; }

    Vec Vec::getCrossTriple(const Vec *b, const Vec *c) const
    {
      cVec v = Vec();
      if(b == NULL){ setError("ERR: getCrossTriple(vec*,vec*): First argument is null" ); return v; }
      if(c == NULL){ setError("ERR: getCrossTriple(vec*,vec*): Second argument is null"); return v; }
      return getCrossTriple(*b,*c);
    }

    Vec Vec::getCrossTriple(const Vec *b, const Vec &c) const
    {
      if(b == NULL){ setError("ERR: getCrossTriple(vec*,vec&): First argument is null"); return Vec(); }
      return getCrossTriple(*b,c);
    }

    Vec Vec::getCrossTriple(const Vec &b, const Vec *c) const
    {
      if(c == NULL){ setError("ERR: getCrossTriple(vec&,vec*): Second argument is null"); return Vec(); }
      return getCrossTriple(b,*c);
    }

    TSP_NUM Vec::getDot(const Vec &b) const
      { return (getX()*b.getX() + getY()*b.getY() + getZ()*b.getZ()); }

    TSP_NUM Vec::getDot(const Vec *b) const
    {
      if(b == NULL){ setError("ERR: getDot(vec*): Argument is null"); return 0; }
      return getDot(*b);
    }

    Vec& Vec::Add(const Vec &b)
      { setX(getX() + b.getX()).setY(getY() + b.getY()).setZ(getZ() + b.getZ()); return *this; }

    Vec& Vec::Add(const Vec *b)
    {
      if(b == NULL){ setError("ERR: Add(vec*): Argument is null"); return *this; }
      Add(*b); return *this;
    }

    Vec& Vec::Add(TSP_NUM x)
      { setX(getX() + x); return *this; }

    Vec& Vec::Add(TSP_NUM x, TSP_NUM y)
      { setX(getX() + x).setY(getY() + y); return *this; }

    Vec& Vec::Add(TSP_NUM x, TSP_NUM y, TSP_NUM z)
      { setX(getX() + x).setY(getY() + y).setZ(getZ() + z); return *this; }

    Vec Vec::getAdd(const Vec *b) const
    {
      cVec v = Vec();
      if(b == NULL){ setError("ERR: getAdd(vec*): Argument is null"); return v; }
      v.Set(this).Add(b); return v;
    }

    Vec Vec::getAdd(const Vec &b) const
      { cVec v = Vec().Set(this).Add(b); return v; }

    Vec Vec::getAdd(TSP_NUM x) const
      { cVec v = Vec(); v.Add(x); return v; }

    Vec Vec::getAdd(TSP_NUM x, TSP_NUM y) const
      { cVec v = Vec(); v.Add(x,y); return v; }

    Vec Vec::getAdd(TSP_NUM x, TSP_NUM y, TSP_NUM z) const
      { cVec v = Vec(); v.Add(x,y,z); return v; }

    Vec& Vec::Sub(const Vec &b)
    {
      setX(getX() - b.getX());
      setY(getY() - b.getY());
      setZ(getZ() - b.getZ());
      return *this;
    }

    Vec& Vec::Sub(const Vec *b)
    {
      if(b == NULL){ setError("ERR: Sub(vec*): Argument is null"); return *this; }
      Sub(*b); return *this;
    }

    Vec& Vec::Sub(TSP_NUM x)
      { setX(getX() - x); return *this; }

    Vec& Vec::Sub(TSP_NUM x, TSP_NUM y)
      { setX(getX() - x).setY(getY() - y); return *this; }

    Vec& Vec::Sub(TSP_NUM x, TSP_NUM y, TSP_NUM z)
      { setX(getX() - x).setY(getY() - y).setZ(getZ() - z); return *this; }

    Vec Vec::getSub(const Vec *b) const
    {
      cVec v = Vec();
      if(b == NULL){ setError("ERR: getSub(vec*): Argument is null"); return v; }
      v.Set(this).Sub(b); return v;
    }

    Vec Vec::getSub(const Vec &b) const
      { cVec v = Vec().Set(this).Sub(b); return v; }

    Vec Vec::getSub(TSP_NUM x) const
      { cVec v = Vec(); v.Sub(x); return v; }

    Vec Vec::getSub(TSP_NUM x, TSP_NUM y) const
      { cVec v = Vec(); v.Sub(x,y); return v; }

    Vec Vec::getSub(TSP_NUM x, TSP_NUM y, TSP_NUM z) const
      { cVec v = Vec(); v.Sub(x,y,z); return v; }

    Vec& Vec::Set(const Vec *b)
    {
      if(b == NULL){ setError("ERR: Set(vec*): Argument is null"); return *this; }
      setX(b->getX()); setY(b->getY()); setZ(b->getZ()); return *this;
    }

    Vec& Vec::Set(const Vec &b){ setX(b.getX()); setY(b.getY()); setZ(b.getZ()); return *this; }

    Vec& Vec::Set(TSP_NUM x, TSP_NUM y, TSP_NUM z){ setX(x); setY(y); setZ(z); return *this; }

    Vec& Vec::Set(TSP_NUM x, TSP_NUM y){ setX(x); setY(y); setZ(0); return *this; }

    Vec& Vec::Set(TSP_NUM x){ setX(x); setY(0); setZ(0); return *this; }

    Vec& Vec::Set(void){ setX(0); setY(0); setZ(0); return *this; }

    TSP_NUM Vec::getCosine(TSP_STR ax) const
    {
      TSP_NUM ab = getDistance();
      if(ab ==  0 ){ setError("ERR: getCosine(str): Base module is zero"); return 0; }
      if(ax == 'x'){ return getX() / ab; }
      if(ax == 'y'){ return getY() / ab; }
      if(ax == 'z'){ return getZ() / ab; }
      return 0;
    }

    Vec& Vec::Mul(TSP_NUM n){ setX(getX() * n); setY(getY() * n); setZ(getZ() * n); return *this; }

    Vec Vec::getMul(TSP_NUM n) const { cVec v = Vec().Set(this).Mul(n); return v; }

    Vec& Vec::Div(TSP_NUM n)
    {
      if(n == 0){ setError("ERR: Div(num): Divide by zero"); return *this; }
      setX(getX() / n); setY(getY() / n); setZ(getZ() / n); return *this;
    }

    Vec& Vec::Div(const Vec &b)
    {
      if(b.getX() == 0){ setError("ERR: Div(vec&): Divide(X) by zero"); return *this; }
      if(b.getY() == 0){ setError("ERR: Div(vec&): Divide(Y) by zero"); return *this; }
      if(b.getZ() == 0){ setError("ERR: Div(vec&): Divide(Z) by zero"); return *this; }
      setX(getX() / b.getX()).setY(getY() / b.getY()).setZ(getZ() / b.getZ()); return *this;
    }

    Vec& Vec::Div(const Vec *b)
    {
      if(b == NULL){ setError("ERR: Div(vec*): Argument is null"); return *this; }
      Div(*b); return *this;
    }

    Vec Vec::getDiv(TSP_NUM n) const
    {
      cVec v = Vec();
      if(n == 0){ setError("ERR: getDiv(num): Divide by zero"); return v; }
      v.Set(this).Div(n); return v;
    }

    Vec Vec::getDiv(const Vec &b) const
    {
      cVec v = Vec(); v.Set(this).Div(b); return v;
    }

    Vec Vec::getDiv(const Vec *b) const
    {
      cVec v = Vec();
      if(b == NULL){ setError("ERR: getDiv(vec*): Argument is null"); return v; }
      v.Set(this).Div(*b); return v;
    }

    Vec Vec::getRound(void) const { cVec v = Vec(); v.Set(this).Round(); return v; }

    Vec Vec::getTrunc(void) const { cVec v = Vec(); v.Set(this).Trunc(); return v; }

    Vec Vec::getFloor(void) const { cVec v = Vec(); v.Set(this).Floor(); return v; }

    Vec Vec::getCeil(void) const { cVec v = Vec(); v.Set(this).Ceil(); return v; }

    Vec& Vec::RoundDigit(unsigned int d){ TSP_NUM mul = pow(10,d); Mul(mul); Round(); Div(mul); return *this; }

    Vec Vec::getRoundDigit(unsigned int d) const { cVec v = Vec(); v.Set(this).RoundDigit(d); return v; }

    TSP_NUM Vec::getAreaParallelogram(const Vec *b) const
    {
      if(b == NULL){ setError("ERR: getAreaParallelogram(vec*): Argument is null"); return 0; }
      return TSP_ABS(getCross(b).getDistance());
    }

    TSP_NUM Vec::getAreaParallelogram(const Vec &b) const
    {
      return TSP_ABS(getCross(b).getDistance());
    }

    TSP_NUM Vec::getAreaTriangle(const Vec *b) const
    {
      if(b == NULL){ setError("ERR: getAreaTriangle(vec*): Argument is null"); return 0; }
      return TSP_ABS(0.5 * getAreaParallelogram(b));
    }

    TSP_NUM Vec::getAreaTriangle(const Vec &b) const
    {
      return TSP_ABS(0.5 * getAreaParallelogram(b));
    }

    TSP_NUM Vec::getMixed(const Vec &b, const Vec &c) const
    {
      cVec v = b.getCross(c); return getDot(v);
    }

    TSP_NUM Vec::getMixed(const Vec *b, const Vec *c) const
    {
      if(b == NULL){ setError("ERR: getMixed(vec*,vec*): First argument is null"); return 0; }
      if(c == NULL){ setError("ERR: getMixed(vec*,vec*): Second argument is null"); return 0; }
      cVec v = b->getCross(c);
      return getDot(v);
    }

    TSP_NUM Vec::getMixed(const Vec *b, const Vec &c) const
    {
      if(b == NULL){ setError("ERR: getMixed(vec*,vec&): First argument is null"); return 0; }
      cVec v = b->getCross(c);
      return getDot(v);
    }

    TSP_NUM Vec::getMixed(const Vec &b, const Vec *c) const
    {
      if(c == NULL){ setError("ERR: getMixed(vec&,vec*): Second argument is null"); return 0; }
      cVec v = b.getCross(c);
      return getDot(v);
    }

    TSP_NUM Vec::getVolumeParallelepiped(const Vec &b, const Vec &c) const
    {
      return TSP_ABS(getMixed(b,c));
    }

    TSP_NUM Vec::getVolumeParallelepiped(const Vec *b, const Vec *c) const
    {
      if(b == NULL){ setError("ERR: getVolumeParallelepiped(vec*,vec*): First argument is null"); return 0; }
      if(c == NULL){ setError("ERR: getVolumeParallelepiped(vec*,vec*): Second argument is null"); return 0; }
      return TSP_ABS(getMixed(b,c));
    }

    TSP_NUM Vec::getVolumeParallelepiped(const Vec *b, const Vec &c) const
    {
      if(b == NULL){ setError("ERR: getVolumeParallelepiped(vec*,vec&): First argument is null"); return 0; }
      return TSP_ABS(getMixed(b,c));
    }

    TSP_NUM Vec::getVolumeParallelepiped(const Vec &b, const Vec *c) const
    {
      if(c == NULL){ setError("ERR: getVolumeParallelepiped(vec&,vec*): Second argument is null"); return 0; }
      return TSP_ABS(getMixed(b,c));
    }

    TSP_NUM Vec::getVolumeTetrahedron(const Vec &b, const Vec &c) const
    {
      return TSP_ABS(getVolumeParallelepiped(b,c) / 6);
    }

    TSP_NUM Vec::getVolumeTetrahedron(const Vec *b, const Vec *c) const
    {
      if(b == NULL){ setError("ERR: getVolumeTetrahedron(vec*,vec*): First argument is null"); return 0; }
      if(c == NULL){ setError("ERR: getVolumeTetrahedron(vec*,vec*): Second argument is null"); return 0; }
      return TSP_ABS(getVolumeParallelepiped(b,c) / 6);
    }

    TSP_NUM Vec::getVolumeTetrahedron(const Vec *b, const Vec &c) const
    {
      if(b == NULL){ setError("ERR: getVolumeTetrahedron(vec*,vec&): First argument is null"); return 0; }
      return TSP_ABS(getVolumeParallelepiped(b,c) / 6);
    }

    TSP_NUM Vec::getVolumeTetrahedron(const Vec &b, const Vec *c) const
    {
      if(c == NULL){ setError("ERR: getVolumeTetrahedron(vec&,vec*): Second argument is null"); return 0; }
      return TSP_ABS(getVolumeParallelepiped(b,c) / 6);
    }

    TSP_BUL Vec::isCoplanar(const Vec &a, const Vec &b) const { return (getMixed(a,b) == 0); }

    TSP_BUL Vec::isCoplanar(const Vec *a, const Vec *b) const
    {
      if(a == NULL){ setError("ERR: isCoplanar(vec*,vec*): First argument is null"); return 0; }
      if(b == NULL){ setError("ERR: isCoplanar(vec*,vec*): Second argument is null"); return 0; }
      return (getMixed(a,b) == 0);
    }

    TSP_BUL Vec::isCoplanar(const Vec &a, const Vec *b) const
    {
      if(b == NULL){ setError("ERR: isCoplanar(vec&,vec*): Second argument is null"); return 0; }
      return (getMixed(a,b) == 0);
    }

    TSP_BUL Vec::isCoplanar(const Vec *a, const Vec &b) const
    {
      if(a == NULL){ setError("ERR: isCoplanar(vec*,vec&): First argument is null"); return 0; }
      return (getMixed(a,b) == 0);
    }

    Vec& Vec::Offset(const Vec &d, TSP_NUM n)
    {
      cVec dir = d.getDirection();
           dir.Mul(n);
      setX(getX() + dir.getX());
      setY(getY() + dir.getY());
      setZ(getZ() + dir.getZ());
      return *this;
    }

    Vec& Vec::Offset(const Vec *d, TSP_NUM n)
    {
      if(d == NULL){ setError("ERR: Offset(dir*,num): Direction is null"); return *this; }
      Offset(*d,n); return *this;
    }

    Vec Vec::getOffset(const Vec *d, TSP_NUM n) const
    {
      cVec v = Vec();
      if(d == NULL){ setError("ERR: getOffset(dir*,num): Direction is null"); return v; }
      v.Set(this).Offset(d,n); return v;
    }

    Vec Vec::getOffset(const Vec &d, TSP_NUM n) const { cVec v = Vec().Set(this).Offset(d,n); return v; }

    Vec& Vec::Neg(void){ setX(-getX()); setY(-getY()); setZ(-getZ()); return *this; }

    Vec Vec::getNeg(void) const { cVec v = Vec().Set(this).Neg(); return v; }
    // X Y Z  ->  Z X Y
    Vec& Vec::RollL(void){ TSP_NUM T = Z; Z = Y; Y = X; X = T; return *this; }
    // X Y Z  ->  Z X Y
    Vec Vec::getRollL(void) const { return Vec(Z,X,Y); }
    // X Y Z  ->  Y Z X
    Vec& Vec::RollR(void){ TSP_NUM T = X; X = Y; Y = Z; Z = T; return *this; }
    // X Y Z  ->  Y Z X
    Vec Vec::getRollR(void) const { return Vec(Y,Z,X); }
    // X Y Z  ->  Y Z 0
    Vec& Vec::ShiftL(void){ X = Y; Y = Z; Z = 0;  return *this; }
    // X Y Z  ->  Y Z 0
    Vec Vec::getShiftL(void) const { return Vec(Y,Z,0); }
    // X Y Z  ->  0 X Y
    Vec& Vec::ShiftR(void){ Z = Y; Y = X; X = 0; return *this; }
    // X Y Z  ->  0 X Y
    Vec Vec::getShiftR(void) const { return Vec(0,X,Y); }

    Vec& Vec::Swap(const void* cmp)
    {
      if(cmp == NULL){ setError("ERR: Swap(str*): Argument is null"); return *this; }
      TSP_NUM T = 0.0; TSP_STR swp[2] = {0};
      const TSP_STR *cms = (const TSP_STR*)cmp;
      swp[0] = cms[0] | 0x20; swp[1] = cms[1] | 0x20;
      if     (!memcmp(swp,"xy",2) || !memcmp(swp,"yx",2)){ T = X; X = Y; Y = T; }
      else if(!memcmp(swp,"yz",2) || !memcmp(swp,"zy",2)){ T = Y; Y = Z; Z = T; }
      else if(!memcmp(swp,"zx",2) || !memcmp(swp,"xz",2)){ T = Y; Y = Z; Z = T; }
      else setError("ERR: Swap(str*): Wrong components <%c%c>",swp[0],swp[1]);
      return *this;
    }

    Vec Vec::getSwap(const void* cmp) const { cVec v = Vec(); v.Set(this).Swap(cmp); return v; }

    Vec& Vec::Center(const Vec &b) // Depth of A is not considered
    { // It must be able taking the center between A and B
      unsigned int cnt = 1; cVec const *pVec = &b;
      while(pVec != NULL){ Add(pVec); cnt++; pVec = pVec->getNext(); } Div(cnt);
      return *this;
    }

    Vec& Vec::Center(const Vec *b)
    {
      if(b == NULL){ setError("ERR: Center(vec*): Argument is null"); return *this; }
      Center(*b); return *this;
    }

    Vec& Vec::Center(TSP_NUM b){ cVec v = Vec(b); Center(v); return *this; }

    Vec Vec::getCenter(const Vec &b) const // Depth of A is used
    {
      cVec va = Vec(); va.Set(this).Center(b);
      cVec vb = Vec(); vb.Set(b).Center(this);
      return (va + vb).Div(2);
    }

    Vec Vec::getCenter(const Vec *b) const
    { // Get the center separately
      if(b == NULL){ setError("ERR: getCenter(vec*): Argument is null"); return *this; }
      return getCenter(*b);
    }

    Vec Vec::getCenter(TSP_NUM b) const { cVec v = Vec(b); v.Center(this); return v; }

    Vec operator%(Vec &a, Vec &b){ return a.getCenter(b); }
    Vec operator%(Vec &a, TSP_NUM b){ cVec v = Vec(b); v.Center(a); return v; }
    Vec operator%(TSP_NUM a, Vec &b){ cVec v = Vec(a); v.Center(b); return v; }
    void operator%=(Vec &a, Vec &b)   { cVec v = (a % b); a.Set(v); }
    void operator%=(Vec &a, TSP_NUM b){ cVec v = (a % b); a.Set(v); }
#endif
