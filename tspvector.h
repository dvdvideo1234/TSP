#ifndef __TSP_VECTOR__H_
    #define __TSP_VECTOR__H_               // Types are MCU dependent
    #define TSP_NUM float                  // General type for floating point number
    #define TSP_STR unsigned char          // General type for strings storage in vector names
    #define TSP_BUL unsigned char          // General type for representing booleans
    #define TSP_ERR_COD "TSP_ERROR: "      // General error message prefix
    #define TSP_ERR_LEN 50
    #define TSP_PI 3.1415926535897931

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
            Vec&           setError(const char *form, ...);
        public:
            friend Vec     operator+ (Vec&, Vec&);
            friend Vec     operator- (Vec&, Vec&);
            friend void    operator+=(Vec&, TSP_NUM);
            friend void    operator+=(Vec&, Vec&);
            friend void    operator-=(Vec&, TSP_NUM);
            friend void    operator-=(Vec&, Vec&);
            friend Vec     operator^ (Vec&, Vec&);
            friend void    operator^=(Vec&, Vec&);
            friend TSP_NUM operator* (Vec&, Vec&);
            friend Vec     operator* (TSP_NUM , Vec&);
            friend Vec     operator* (Vec&, TSP_NUM);
            friend void    operator*=(Vec&, TSP_NUM);
            friend void    operator*=(Vec&, Vec&);
            friend Vec     operator/ (Vec&, TSP_NUM);
            friend void    operator/=(Vec&, TSP_NUM);
            friend TSP_BUL operator==(Vec&, Vec&);
            friend TSP_BUL operator!=(Vec&, Vec&);
            friend TSP_BUL operator>=(Vec&, Vec&);
            friend TSP_BUL operator<=(Vec&, Vec&);
            friend TSP_BUL operator> (Vec&, Vec&);
            friend TSP_BUL operator< (Vec&, Vec&);
            friend class Vec  operator++(Vec&, int);
            friend class Vec  operator--(Vec&, int);
            friend class Vec& operator++(Vec&);
            friend class Vec& operator--(Vec&);
            TSP_BUL         isZero(void);
            TSP_BUL         isValid(void);
            TSP_BUL         isCollinear (class Vec *b);
            TSP_BUL         isCollinear (class Vec &b);
            TSP_BUL         isOrthogonal(class Vec *b);
            TSP_BUL         isOrthogonal(class Vec &b);
            TSP_BUL         isCoplanar(class Vec &a, class Vec &b);
            TSP_BUL         isCoplanar(class Vec *a, class Vec *b);
            TSP_BUL         isCoplanar(class Vec *a, class Vec &b);
            TSP_BUL         isCoplanar(class Vec &a, class Vec *b);
            TSP_NUM        getDistance(class Vec *b);
            TSP_NUM        getDistance(class Vec &b);
            TSP_NUM        getDistance(void);
            class Vec&        Direction(class Vec *b);
            class Vec&        Direction(class Vec &b);
            class Vec&        Direction(void);
            class Vec      getDirection(class Vec *b);
            class Vec      getDirection(class Vec &b);
            class Vec      getDirection(void);
            TSP_NUM        getX(void){ return X; };
            TSP_NUM        getY(void){ return Y; };
            TSP_NUM        getZ(void){ return Z; };
            void          *getUser(void){ return User; };
            TSP_STR       *getName(void){ return Name; };
            class Vec     *getNext(void){ return Next; };
            TSP_STR       *getError(void);
            class Vec&     setX(TSP_NUM x){ X = x; return *this; };
            class Vec&     setY(TSP_NUM y){ Y = y; return *this; };
            class Vec&     setZ(TSP_NUM z){ Z = z; return *this; };
            class Vec&     setUser(void *pUser){ User = pUser; return *this; };
            class Vec&     setName(const void *pName){ Name = (TSP_STR*)pName; return *this; };
            class Vec&     setNext(class  Vec *pNext){ Next = pNext;      return *this; };
            TSP_NUM        getAngleDeg(class  Vec *b);
            TSP_NUM        getAngleDeg(class  Vec &b);
            TSP_NUM        getAngleRad(class  Vec *b);
            TSP_NUM        getAngleRad(class  Vec &b);
            TSP_NUM        getAreaTriangle(class Vec *b);
            TSP_NUM        getAreaTriangle(class Vec &b);
            TSP_NUM        getAreaParallelogram(class Vec *b);
            TSP_NUM        getAreaParallelogram(class Vec &b);
            TSP_NUM        getVolumeTetrahedron(class Vec &b, class Vec &c);
            TSP_NUM        getVolumeTetrahedron(class Vec *b, class Vec *c);
            TSP_NUM        getVolumeTetrahedron(class Vec *b, class Vec &c);
            TSP_NUM        getVolumeTetrahedron(class Vec &b, class Vec *c);
            TSP_NUM        getVolumeParallelepiped(class Vec &b, class Vec &c);
            TSP_NUM        getVolumeParallelepiped(class Vec *b, class Vec *c);
            TSP_NUM        getVolumeParallelepiped(class Vec *b, class Vec &c);
            TSP_NUM        getVolumeParallelepiped(class Vec &b, class Vec *c);
            class Vec&        Round(void){ X = roundf(X); Y = roundf(Y); Z = roundf(Z); return *this; };
            class Vec      getRound(void);
            class Vec&        RoundDigit(unsigned int d);
            class Vec      getRoundDigit(unsigned int d);
            class Vec&        Trunc(void){ X = truncf(X); Y = truncf(Y); Z = truncf(Z);return *this; };
            class Vec      getTrunc(void);
            class Vec&        Floor(void){ X = floorf(X); Y = floorf(Y); Z = floorf(Z);return *this; };
            class Vec      getFloor(void);
            class Vec&        Ceil(void){ X = ceilf(X); Y = ceilf(Y); Z = ceilf(Z); return *this; };
            class Vec      getCeil(void);
            class Vec&        Project(class Vec *b);
            class Vec&        Project(class Vec &b);
            class Vec      getProject(class Vec *b);
            class Vec      getProject(class Vec &b);
            class Vec&        Add(class Vec *b);
            class Vec&        Add(class Vec &b);
            class Vec      getAdd(class Vec *b);
            class Vec      getAdd(class Vec &b);
            class Vec&        Sub(class Vec *b);
            class Vec&        Sub(class Vec &b);
            class Vec      getSub(class Vec *b);
            class Vec      getSub(class Vec &b);
            TSP_NUM        getCosine(TSP_STR);
            class Vec&        Neg(void);
            class Vec      getNeg(void);
            class Vec&        Mul(TSP_NUM n);
            class Vec      getMul(TSP_NUM n);
            class Vec&        Div(TSP_NUM n);
            class Vec      getDiv(TSP_NUM n);
            TSP_NUM        getMixed(class Vec &b, class Vec &c);
            TSP_NUM        getMixed(class Vec *b, class Vec *c);
            TSP_NUM        getMixed(class Vec *b, class Vec &c);
            TSP_NUM        getMixed(class Vec &b, class Vec *c);
            class Vec&        CrossTriple(class Vec &b, class Vec &c);
            class Vec&        CrossTriple(class Vec *b, class Vec *c);
            class Vec&        CrossTriple(class Vec *b, class Vec &c);
            class Vec&        CrossTriple(class Vec &b, class Vec *c);
            class Vec      getCrossTriple(class Vec &b, class Vec &c);
            class Vec      getCrossTriple(class Vec *b, class Vec *c);
            class Vec      getCrossTriple(class Vec *b, class Vec &c);
            class Vec      getCrossTriple(class Vec &b, class Vec *c);
            class Vec&        Set(class Vec &b);
            class Vec&        Set(class Vec *b);
            class Vec&        Set(TSP_NUM x, TSP_NUM y, TSP_NUM z);
            class Vec&        Set(TSP_NUM x, TSP_NUM y);
            class Vec&        Set(TSP_NUM x);
            class Vec&        Set(void);
            class Vec&        Offset(class Vec &Dir, TSP_NUM n);
            class Vec&        Offset(class Vec *Dir, TSP_NUM n);
            class Vec      getOffset(class Vec &Dir, TSP_NUM n);
            class Vec      getOffset(class Vec *Dir, TSP_NUM n);
            class Vec&        Cross(class Vec *b);
            class Vec&        Cross(class Vec &b);
            class Vec      getCross(class Vec *b);
            class Vec      getCross(class Vec &b);
            TSP_NUM        getDot(Vec *b);
            TSP_NUM        getDot(class Vec &b);
            class Vec&        RollR(void);
            class Vec      getRollR(void);
            class Vec&        RollL(void);
            class Vec      getRollL(void);
            class Vec&        Swap(const void* Comp);
            class Vec      getSwap(const void* Comp);
            class Vec&        Print(void);
            class Vec&        PrintTrajectory(void);
                              Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z, const void *name, void *user, class Vec *next);
                              Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z, const void *name, class Vec *next);
                              Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z, const void *name);
                              Vec(const void *name);
                              Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z);
                              Vec(TSP_NUM x, TSP_NUM y);
                              Vec(TSP_NUM x);
                              Vec(void);
                             ~Vec(void){ free(Name); };
    } cVec;

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

    Vec::Vec(TSP_NUM x, TSP_NUM y, TSP_NUM z)
    {
      setX(x); setY(y); setZ(z); setUser(NULL); setName(NULL); setNext(NULL);
    }

    Vec::Vec(TSP_NUM x, TSP_NUM y)
    {
      setX(x); setY(y); setZ(0.0); setUser(NULL); setName(NULL); setNext(NULL);
    }

    Vec::Vec(TSP_NUM x)
    {
      setX(x); setY(0.0); setZ(0.0); setUser(NULL); setName(NULL); setNext(NULL);
    }

    Vec::Vec()
    {
      setX(0.0); setY(0.0); setZ(0.0); setUser(NULL); setName(NULL); setNext(NULL);
    }

    Vec& Vec::Print(void)
    {
      printf("\n\rVec %p > %p --> %s, %p\n\rXYZ = { %15.8f, %15.8f, %15.8f }\n\r",
         this,getNext(),getName(),getUser(),getX(),getY(),getZ());
      return *this;
    }

    Vec& Vec::PrintTrajectory(void)
    {
      cVec *p = this;
      while(p != NULL)
      {
        p->Print();
        p = p->getNext();
      }
      return *this;
    }

    TSP_STR* Vec::getError(void)
    {
      if(!isValid()){ return Name+sizeof(TSP_ERR_COD)-1; }
      return (TSP_STR*)NULL; // There is no error
    }

    Vec& Vec::setError(const char *form, ...)
    {
      va_list args; unsigned int sz = sizeof(TSP_ERR_COD); free(Name);
      if(NULL == (Name = (TSP_STR*)malloc((TSP_ERR_LEN + sz)*sizeof(TSP_STR)))){ return *this; }
      va_start (args, form); memcpy(Name,TSP_ERR_COD,sizeof(TSP_ERR_COD));
      vsprintf((char*)(Name+sz-1), form, args);
      va_end(args); return *this;
    }

    TSP_BUL Vec::isValid(void)
    {
      if(NULL == Name){ return (1==1); }
      return memcmp(Name,TSP_ERR_COD,sizeof(TSP_ERR_COD)-1);
    }

    TSP_BUL Vec::isZero(void)
    {
      return (X==0 && Y==0 && Z==0);
    }

    TSP_BUL Vec::isOrthogonal(class Vec *b)
    {
      if(b == NULL){ setError("isOrthogonal(vec*): Argument is null"); return 0; }
      return (getDot(b) == 0);
    }

    TSP_BUL Vec::isOrthogonal(class Vec &b)
    {
      return (getDot(b) == 0);
    }

    TSP_BUL Vec::isCollinear(class Vec *b)
    {
      if(b == NULL){ setError("isCollinear(vec*): Argument is null"); return 0; }
      TSP_NUM x = getX() / b->getX();
      TSP_NUM y = getY() / b->getY();
      TSP_NUM z = getZ() / b->getZ();
      return (x == y && y == z && z == x);
    }

    TSP_BUL Vec::isCollinear(class Vec &b)
    {
      TSP_NUM x = getX() / b.getX();
      TSP_NUM y = getY() / b.getY();
      TSP_NUM z = getZ() / b.getZ();
      return (x == y && y == z && z == x);
    }

    TSP_NUM Vec::getDistance(void)
    {
      TSP_NUM x = getX();
      TSP_NUM y = getY();
      TSP_NUM z = getZ();
      return sqrt(x*x + y*y + z*z);
    }

    TSP_NUM Vec::getDistance(class Vec *b)
    {
      if(b == NULL){ return getDistance(); }
      TSP_NUM x = getX() - b->getX();
      TSP_NUM y = getY() - b->getY();
      TSP_NUM z = getZ() - b->getZ();
      return sqrt(x*x + y*y + z*z);
    }

    TSP_NUM Vec::getDistance(class Vec &b)
    {
      TSP_NUM x = getX() - b.getX();
      TSP_NUM y = getY() - b.getY();
      TSP_NUM z = getZ() - b.getZ();
      return sqrt(x*x + y*y + z*z);
    }

    Vec& Vec::Direction(void)
    {
      TSP_NUM D = getDistance();
      if(D == 0){ setError("Direction(void): Vector module is zero"); return *this; }
      setX(getX() / D);
      setY(getY() / D);
      setZ(getZ() / D);
      return *this;
    }

    Vec& Vec::Direction(class Vec *b)
    {
      if(b == NULL){ return Direction(); }
      TSP_NUM D = getDistance(b);
      if(D == 0){ setError("Direction(vec*): Vector module is zero"); return *this; }
      setX((getX() - b->getX()) / D);
      setY((getY() - b->getY()) / D);
      setZ((getZ() - b->getZ()) / D);
      return *this;
    }

    Vec& Vec::Direction(class Vec &b)
    {
      TSP_NUM D = getDistance(&b);
      if(D == 0){ setError("Direction(vec&): Vector module is zero"); return *this; }
      setX((getX() - b.getX()) / D);
      setY((getY() - b.getY()) / D);
      setZ((getZ() - b.getZ()) / D);
      return *this;
    }

    Vec Vec::getDirection(void)
    {
      cVec v = Vec();
      TSP_NUM D = getDistance();
      if(D == 0){ v.setError("getDirection(void): Vector module is zero"); return v; }
      v.Set(this).Direction(); return v;
    }

    Vec Vec::getDirection(class Vec *b)
    {
      if(b == NULL){ return getDirection(); }
      cVec v = Vec();
      TSP_NUM D = getDistance(b);
      if(D == 0){ v.setError("getDirection(vec*): Argument module is zero"); return v; }
      v.Set(this).Direction(b); return v;
    }

    Vec Vec::getDirection(class Vec &b)
    {
      cVec v = Vec();
      TSP_NUM D = getDistance(&b);
      if  (D == 0){ v.setError("getDirection(vec&): Argument module is zero"); return v; }
      v.Set(this).Direction(b); return v;
    }

    Vec operator^(Vec &a, Vec &b)
    {
      return a.getCross(b);
    }

    TSP_NUM operator*(Vec &a, Vec &b)
    {
      return a.getDot(b);
    }

    Vec operator+(Vec &a, Vec &b)
    {
      return Vec(a.getX() + b.getX(), a.getY() + b.getY(), a.getZ() + b.getZ());
    }

    Vec operator-(Vec &a, Vec &b)
    {
      return Vec(a.getX() - b.getX(), a.getY() - b.getY(), a.getZ() - b.getZ());
    }

    void operator+=(Vec &a, TSP_NUM n)
    {
      a.setX(a.getX() + n);
    }

    void operator+=(Vec &a, Vec &b)
    {
      a.Add(b);
    }

    void operator^=(Vec &a, Vec &b)
    {
      a.Cross(b);
    }

    void operator*=(Vec &a, Vec &b)
    {
      a.Mul(a.getDot(b));
    }

    void operator-=(Vec &a, TSP_NUM n)
    {
      a.setX(a.getX() - n);
    }

    void operator-=(Vec &a, Vec &b)
    {
      a.Sub(b);
    }

    Vec operator*(TSP_NUM n, Vec &b)
    {
      return Vec(n * b.getX(), n * b.getY(), n * b.getZ());
    }

    Vec operator*(Vec &b, TSP_NUM n)
    {
      return Vec(n * b.getX(), n * b.getY(), n * b.getZ());
    }

    Vec  operator/(Vec &b, TSP_NUM n)
    {
      cVec v = Vec();
      if(n == 0){ v.setError("operator/(vec&,num): Divide by zero"); return v; }
      v.Set(b.getX() / n, b.getY() / n, b.getZ() / n); return v;
    }

    void operator*=(Vec &a, TSP_NUM n)
    {
      a.Mul(n);
    }

    void operator/=(Vec &a, TSP_NUM n)
    {
      if(n == 0){ a.setError("oerator(/=): Divide by zero"); return; }
      a.Div(n);
    }

    TSP_BUL operator==(Vec &a, Vec &b)
    {
      return ((a.getX() == b.getX()) &&
              (a.getY() == b.getY()) &&
              (a.getZ() == b.getZ()));
    }

    TSP_BUL operator!=(Vec &a, Vec &b)
    {
      return ((a.getX() != b.getX()) ||
              (a.getY() != b.getY()) ||
              (a.getZ() != b.getZ()));
    }

    TSP_BUL operator>=(Vec &a, Vec &b)
    {
      return (a.getDistance() >= b.getDistance());
    }

    TSP_BUL operator<=(Vec &a, Vec &b)
    {
      return (a.getDistance() <= b.getDistance());
    }

    TSP_BUL operator>(Vec &a, Vec &b)
    {
      return (a.getDistance() > b.getDistance());
    }

    TSP_BUL operator<(Vec &a, Vec &b)
    {
      return (a.getDistance() < b.getDistance());
    }

    Vec operator++(Vec &b, int a)
    {
      cVec dr = b.getDirection();
      b.Add(dr); dr.Sub(b).Neg();
      return dr;
    }

    Vec operator--(Vec &b, int a)
    {
      cVec dr = b.getDirection();
      b.Sub(dr); dr.Add(b);
      return dr;
    }

    Vec& operator++(Vec &b)
    {
      cVec dr = b.getDirection();
      b.Add(dr); return b;
    }

    Vec& operator--(Vec &b)
    {
      cVec dr = b.getDirection();
      b.Sub(dr); return b;
    }

    TSP_NUM Vec::getAngleRad(class Vec *b)
    {
      if(b == NULL){ setError("getAngleRad(vec*): Argument is null"); return 0; }
      TSP_NUM dot = getDot(b);
      TSP_NUM abs = getDistance();
      TSP_NUM abv = b->getDistance();
      if(abs == 0){ setError("getAngleRad(vec*): Base module is zero"); return 0; }
      if(abv == 0){ setError("getAngleRad(vec*): Argument module is zero"); return 0; }
      return acos(dot / ( abs * abv ));
    }

    TSP_NUM Vec::getAngleRad(class Vec &b)
    {
      TSP_NUM dot = getDot(&b);
      TSP_NUM abs = getDistance();
      TSP_NUM abv = b.getDistance();
      if(abs == 0){ setError("getAngleRad(vec*): Base module is zero"); return 0; }
      if(abv == 0){ setError("getAngleRad(vec*): Argument module is zero"); return 0; }
      return acos(dot / ( abs * abv ));
    }

    TSP_NUM Vec::getAngleDeg(class Vec &b)
    {
      return ( getAngleRad(&b) * ( 180 / TSP_PI));
    }

    TSP_NUM Vec::getAngleDeg(class Vec *b)
    {
      if(b == NULL){ setError("getAngleDeg(vec*): Argument is null"); return 0; }
      return ( getAngleRad(b) * ( 180 / TSP_PI));
    }

    Vec& Vec::Project(class Vec *b)
    {
      if(b == NULL){ setError("getAngleDeg(vec*): Argument is null"); return *this; }
      TSP_NUM cpyX = b->getX();
      TSP_NUM cpyY = b->getY();
      TSP_NUM cpyZ = b->getZ();
      TSP_NUM dst2 = cpyX*cpyX + cpyY*cpyY + cpyZ*cpyZ;
      if(dst2 == 0){ setError("Project(vec*): Argument module is zero"); return *this; }
      TSP_NUM dotp = getDot(b) / dst2;
      Set(dotp*cpyX, dotp*cpyY, dotp*cpyZ);
      return *this;
    }

    Vec& Vec::Project(class Vec &b)
    {
      TSP_NUM cpyX = b.getX();
      TSP_NUM cpyY = b.getY();
      TSP_NUM cpyZ = b.getZ();
      TSP_NUM dst2 = cpyX*cpyX + cpyY*cpyY + cpyZ*cpyZ;
      if(dst2 == 0){ setError("Project(vec&): Argument module is zero"); return *this; }
      TSP_NUM dotp = getDot(b) / dst2;
      Set(dotp*cpyX, dotp*cpyY, dotp*cpyZ);
      return *this;
    }

    Vec Vec::getProject(class Vec *b)
    {
      cVec v = Vec();
      if(b == NULL){ v.setError("getProject(vec*): Argument is null"); return v;}
      TSP_NUM cpyX = b->getX();
      TSP_NUM cpyY = b->getY();
      TSP_NUM cpyZ = b->getZ();
      TSP_NUM dst2 = cpyX*cpyX + cpyY*cpyY + cpyZ*cpyZ;
      if(dst2 == 0){ v.setError("getProject(vec*): Argument module is zero"); return v; }
      TSP_NUM dotp  = getDot(b) / dst2; v.Set(dotp*cpyX, dotp*cpyY, dotp*cpyZ); return v;
    }

    Vec Vec::getProject(class Vec &b)
    {
      cVec v = Vec();
      TSP_NUM cpyX = b.getX();
      TSP_NUM cpyY = b.getY();
      TSP_NUM cpyZ = b.getZ();
      TSP_NUM dst2 = cpyX*cpyX + cpyY*cpyY + cpyZ*cpyZ;
      if(dst2 == 0){ v.setError("getProject(vec&): Argument module is zero"); return v; }
      TSP_NUM dotp = getDot(b) / dst2; v.Set(dotp*cpyX, dotp*cpyY, dotp*cpyZ); return v;
    }

    Vec& Vec::Cross(class Vec *b)
    {
      if(b == NULL){ setError("Cross(vec*): Argument is null"); return *this; }
      Set((getY() * b->getZ()) - (getZ() * b->getY()),
          (getZ() * b->getX()) - (getX() * b->getZ()),
          (getX() * b->getY()) - (getY() * b->getX()));
      return *this;
    }

    Vec& Vec::Cross(class Vec &b)
    {
      Set((getY() * b.getZ()) - (getZ() * b.getY()),
          (getZ() * b.getX()) - (getX() * b.getZ()),
          (getX() * b.getY()) - (getY() * b.getX()));
      return *this;
    }

    Vec Vec::getCross(class Vec *b)
    {
      cVec v = Vec();
      if(b == NULL){ v.setError("getCross(vec*): Argument is null"); return v; }
      v.Set(this).Cross(b); return v;
    }

    Vec Vec::getCross(class Vec &b)
    {
      cVec v = Vec(); v.Set(this).Cross(b); return v;
    }

    Vec& Vec::CrossTriple(class Vec &b, class Vec &c)
    {
      TSP_NUM ac = getDot(c);
      TSP_NUM ab = getDot(b);
      Set((ac * b.getX()) - (ab * c.getX()),
          (ac * b.getY()) - (ab * c.getY()),
          (ac * b.getZ()) - (ab * c.getZ()));
      return *this;
    }

    Vec& Vec::CrossTriple(class Vec *b, class Vec *c)
    {
      if(b == NULL){ setError("CrossTriple(vec*, vec*): First argument module is null"); return *this; }
      if(c == NULL){ setError("CrossTriple(vec*, vec*): Second argument module is null"); return *this; }
      TSP_NUM ac = getDot(c);
      TSP_NUM ab = getDot(b);
      Set((ac * b->getX()) - (ab * c->getX()),
          (ac * b->getY()) - (ab * c->getY()),
          (ac * b->getZ()) - (ab * c->getZ()));
      return *this;
    }
    Vec& Vec::CrossTriple(class Vec *b, class Vec &c)
    {
      if(b == NULL){ setError("CrossTriple(vec&): First argument is null"); return *this; }
      TSP_NUM ac = getDot(c);
      TSP_NUM ab = getDot(b);
      Set((ac * b->getX()) - (ab * c.getX()),
          (ac * b->getY()) - (ab * c.getY()),
          (ac * b->getZ()) - (ab * c.getZ()));
      return *this;
    }

    Vec& Vec::CrossTriple(class Vec &b, class Vec *c)
    {
      if(c == NULL){ setError("CrossTriple(vec&): Second argument is null"); return *this; }
      TSP_NUM ac = getDot(c);
      TSP_NUM ab = getDot(b);
      Set((ac * b.getX()) - (ab * c->getX()),
          (ac * b.getY()) - (ab * c->getY()),
          (ac * b.getZ()) - (ab * c->getZ()));
      return *this;
    }

    Vec Vec::getCrossTriple(class Vec &b, class Vec &c)
    {
      cVec v = Vec().Set(this).CrossTriple(b,c); return v;
    }

    Vec Vec::getCrossTriple(class Vec *b, class Vec *c)
    {
      cVec v = Vec();
      if(b == NULL){ v.setError("getCrossTriple(vec*,vec*): First argument is null"); return v; }
      if(c == NULL){ v.setError("getCrossTriple(vec*,vec*): Second argument is null"); return v; }
      v.Set(this).CrossTriple(b,c); return v;
    }

    Vec Vec::getCrossTriple(class Vec *b, class Vec &c)
    {
      cVec v = Vec();
      if(b == NULL){ v.setError("getCrossTriple(vec*,vec&): First argument is null"); return v; }
      v.Set(this).CrossTriple(b,c); return v;
    }

    Vec Vec::getCrossTriple(class Vec &b, class Vec *c)
    {
      cVec v = Vec();
      if(c == NULL){ v.setError("getCrossTriple(vec&,vec*): Second argument is null"); return v; }
      v.Set(this).CrossTriple(b,c); return v;
    }

    TSP_NUM Vec::getDot(class Vec *b)
    {
      if(b == NULL){ setError("getDot(vec*): Argument is null"); return 0; }
      return (getX()*b->getX() +
              getY()*b->getY() +
              getZ()*b->getZ());
    }

    TSP_NUM Vec::getDot(class Vec &b)
    {
      return (getX()*b.getX() +
              getY()*b.getY() +
              getZ()*b.getZ());
    }

    Vec& Vec::Add(class Vec *b)
    {
      if(b == NULL){ setError("Add(vec*): Argument is null"); return *this; }
      setX(getX() + b->getX());
      setY(getY() + b->getY());
      setZ(getZ() + b->getZ());
      return *this;
    }

    Vec& Vec::Add(class Vec &b)
    {
      setX(getX() + b.getX());
      setY(getY() + b.getY());
      setZ(getZ() + b.getZ());
      return *this;
    }

    Vec Vec::getAdd(class Vec *b)
    {
      cVec v = Vec();
      if(b == NULL){ v.setError("getAdd(vec*): Argument is null"); return v; }
      v.Set(this).Add(b); return v;
    }

    Vec Vec::getAdd(class Vec &b)
    {
      cVec v = Vec().Set(this).Add(b); return v;
    }

    Vec& Vec::Sub(class Vec *b)
    {
      if(b == NULL){ setError("Sub(vec*): Argument is null"); return *this; }
      setX(getX() - b->getX());
      setY(getY() - b->getY());
      setZ(getZ() - b->getZ());
      return *this;
    }

    Vec& Vec::Sub(class Vec &b)
    {
      setX(getX() - b.getX());
      setY(getY() - b.getY());
      setZ(getZ() - b.getZ());
      return *this;
    }

    Vec Vec::getSub(class Vec *b)
    {
      cVec v = Vec();
      if(b == NULL){ v.setError("getSub(vec*): Argument is null"); return v; }
      v.Set(this).Sub(b); return v;
    }

    Vec Vec::getSub(class Vec &b)
    {
      cVec v = Vec().Set(this).Sub(b); return v;
    }

    Vec& Vec::Set(class Vec *b)
    {
      if(b == NULL){ setError("Set(vec*): Argument is null"); return *this; }
      setX(b->getX()); setY(b->getY()); setZ(b->getZ()); return *this;
    }

    Vec& Vec::Set(class Vec &b)
    {
      setX(b.getX()); setY(b.getY()); setZ(b.getZ()); return *this;
    }

    Vec& Vec::Set(TSP_NUM x, TSP_NUM y, TSP_NUM z)
    {
      setX(x); setY(y); setZ(z); return *this;
    }

    Vec& Vec::Set(TSP_NUM x, TSP_NUM y)
    {
      setX(x); setY(y); setZ(0); return *this;
    }

    Vec& Vec::Set(TSP_NUM x)
    {
      setX(x); setY(0); setZ(0); return *this;
    }

    Vec& Vec::Set(void)
    {
      setX(0); setY(0); setZ(0); return *this;
    }

    TSP_NUM Vec::getCosine(TSP_STR ax)
    {
      TSP_NUM ab = getDistance();
      if(ab ==  0 ){ setError("getCrossTriple(str): Base module is zero"); return 0; }
      if(ax == 'x'){ return getX() / ab; }
      if(ax == 'y'){ return getY() / ab; }
      if(ax == 'z'){ return getZ() / ab; }
      return 0;
    }

    Vec& Vec::Mul(TSP_NUM n)
    {
      setX(getX() * n); setY(getY() * n); setZ(getZ() * n); return *this;
    }

    Vec Vec::getMul(TSP_NUM n)
    {
      cVec v = Vec().Set(this).Mul(n); return v;
    }

    Vec& Vec::Div(TSP_NUM n)
    {
      if(n == 0){ setError("Div(num): Divide by zero"); return *this; }
      setX(getX() / n); setY(getY() / n); setZ(getZ() / n); return *this;
    }

    Vec Vec::getDiv(TSP_NUM n)
    {
      cVec v = Vec();
      if(n == 0){ v.setError("getDiv(num): Divide by zero"); return v; }
      v.Set(this).Div(n); return v;
    }
    Vec Vec::getRound(void)
    {
      cVec v = Vec();
      v.Set(this).Round();
      return v;
    }

    Vec Vec::getTrunc(void)
    {
      cVec v = Vec();
      v.Set(this).Trunc();
      return v;
    }

    Vec Vec::getFloor(void)
    {
      cVec v = Vec();
      v.Set(this).Floor();
      return v;
    }

    Vec Vec::getCeil(void)
    {
      cVec v = Vec();
      v.Set(this).Ceil();
      return v;
    }

    Vec& Vec::RoundDigit(unsigned int d)
    {
      TSP_NUM mul = pow(10,d);
      Mul(mul); Round(); Div(mul);
      return *this;
    }

    Vec Vec::getRoundDigit(unsigned int d)
    {
      cVec v = Vec();
      v.Set(this).RoundDigit(d);
      return v;
    }

    TSP_NUM Vec::getAreaParallelogram(class Vec *b)
    {
      if(b == NULL){ setError("getAreaParallelogram(vec*): Argument is null"); return 0; }
      return fabs(getCross(b).getDistance());
    }

    TSP_NUM Vec::getAreaParallelogram(class Vec &b)
    {
      return fabs(getCross(b).getDistance());
    }

    TSP_NUM Vec::getAreaTriangle(class Vec *b)
    {
      if(b == NULL){ setError("getAreaTriangle(vec*): Argument is null"); return 0; }
      return fabs(0.5 * getAreaParallelogram(b));
    }

    TSP_NUM Vec::getAreaTriangle(class Vec &b)
    {
      return fabs(0.5 * getAreaParallelogram(b));
    }

    TSP_NUM Vec::getMixed(class Vec &b, class Vec &c)
    {
      cVec T = b.getCross(c); return getDot(T);
    }

    TSP_NUM Vec::getMixed(class Vec *b, class Vec *c)
    {
      if(b == NULL){ setError("getMixed(vec*,vec*): First argument is null"); return 0; }
      if(c == NULL){ setError("getMixed(vec*,vec*): Second argument is null"); return 0; }
      cVec T = b->getCross(c);
      return getDot(T);
    }

    TSP_NUM Vec::getMixed(class Vec *b, class Vec &c)
    {
      if(b == NULL){ setError("getMixed(vec*,vec&): First argument is null"); return 0; }
      cVec T = b->getCross(c);
      return getDot(T);
    }

    TSP_NUM Vec::getMixed(class Vec &b, class Vec *c)
    {
      if(c == NULL){ setError("getMixed(vec&,vec*): Second argument is null"); return 0; }
      cVec T = b.getCross(c);
      return getDot(T);
    }

    TSP_NUM Vec::getVolumeParallelepiped(class Vec &b, class Vec &c)
    {
      return fabs(getMixed(b,c));
    }

    TSP_NUM Vec::getVolumeParallelepiped(class Vec *b, class Vec *c)
    {
      if(b == NULL){ setError("getVolumeParallelepiped(vec*,vec*): First argument is null"); return 0; }
      if(c == NULL){ setError("getVolumeParallelepiped(vec*,vec*): Second argument is null"); return 0; }
      return fabs(getMixed(b,c));
    }

    TSP_NUM Vec::getVolumeParallelepiped(class Vec *b, class Vec &c)
    {
      if(b == NULL){ setError("getVolumeParallelepiped(vec*,vec&): First argument is null"); return 0; }
      return fabs(getMixed(b,c));
    }

    TSP_NUM Vec::getVolumeParallelepiped(class Vec &b, class Vec *c)
    {
      if(c == NULL){ setError("getVolumeParallelepiped(vec&,vec*): Second argument is null"); return 0; }
      return fabs(getMixed(b,c));
    }

    TSP_NUM Vec::getVolumeTetrahedron(class Vec &b, class Vec &c)
    {
      return fabs(getVolumeParallelepiped(b,c) / 6);
    }

    TSP_NUM Vec::getVolumeTetrahedron(class Vec *b, class Vec *c)
    {
      if(b == NULL){ setError("getVolumeTetrahedron(vec*,vec*): First argument is null"); return 0; }
      if(c == NULL){ setError("getVolumeTetrahedron(vec*,vec*): Second argument is null"); return 0; }
      return fabs(getVolumeParallelepiped(b,c) / 6);
    }

    TSP_NUM Vec::getVolumeTetrahedron(class Vec *b, class Vec &c)
    {
      if(b == NULL){ setError("getVolumeTetrahedron(vec*,vec&): First argument is null"); return 0; }
      return fabs(getVolumeParallelepiped(b,c) / 6);
    }

    TSP_NUM Vec::getVolumeTetrahedron(class Vec &b, class Vec *c)
    {
      if(c == NULL){ setError("getVolumeTetrahedron(vec&,vec*): Second argument is null"); return 0; }
      return fabs(getVolumeParallelepiped(b,c) / 6);
    }

    TSP_BUL Vec::isCoplanar(class Vec &a, class Vec &b)
    {
      return (getMixed(a,b) == 0);
    }

    TSP_BUL Vec::isCoplanar(class Vec *a, class Vec *b)
    {
      return (getMixed(a,b) == 0);
    }

    TSP_BUL Vec::isCoplanar(class Vec &a, class Vec *b)
    {
      return (getMixed(a,b) == 0);
    }

    TSP_BUL Vec::isCoplanar(class Vec *a, class Vec &b)
    {
      return (getMixed(a,b) == 0);
    }

    Vec& Vec::Offset(class Vec *dir, TSP_NUM n)
    {
      if(dir == NULL){ setError("Offset(dir*,num): Direction is null"); return *this; }
      cVec D = dir->getDirection();
           D.Mul(n);
      setX(getX() + D.getX());
      setY(getY() + D.getY());
      setZ(getZ() + D.getZ());
      return *this;
    }

    Vec& Vec::Offset(class Vec &dir, TSP_NUM n)
    {
      cVec D = dir.getDirection();
           D.Mul(n);
      setX(getX() + D.getX());
      setY(getY() + D.getY());
      setZ(getZ() + D.getZ());
      return *this;
    }

    Vec Vec::getOffset(class Vec *dir, TSP_NUM n)
    {
      cVec v = Vec();
      if(dir == NULL){ v.setError("getOffset(dir*,num): Direction is null"); return v; }
      v.Set(this).Offset(dir,n); return v;
    }

    Vec Vec::getOffset(class Vec &dir, TSP_NUM n)
    {
      cVec v = Vec().Set(this).Offset(dir,n); return v;
    }

    Vec& Vec::Neg(void)
    {
      setX(-getX());
      setY(-getY());
      setZ(-getZ());
      return *this;
    }

    Vec Vec::getNeg(void)
    {
      cVec v = Vec().Set(this).Neg(); return v;
    }

    Vec& Vec::RollL(void)
    {  // X Y Z  ->  Z X Y
      TSP_NUM T = Z; Z = Y;
              Y = X; X = T;
      return *this;
    }

    Vec Vec::getRollL(void)
    {  // X Y Z  ->  Z X Y
      return Vec(Z,X,Y);
    }

    Vec& Vec::RollR(void)
    {  // X Y Z  ->  Y Z X
      TSP_NUM T = X; X = Y;
              Y = Z; Z = T;
      return *this;
    }

    Vec Vec::getRollR(void)
    {  // X Y Z  ->  Y Z X
      return Vec(Y,Z,X);
    }

    Vec& Vec::Swap(const void* cmp)
    {
      TSP_NUM T      = 0.0;
      TSP_STR swp[35] = {0};
      const TSP_STR *cms   = (const TSP_STR*)cmp;
      swp[0] = cms[0] | 0x20;
      swp[1] = cms[1] | 0x20;
      if     (!memcmp(swp,"xy",2) || !memcmp(swp,"yx",2)){ T = X; X = Y; Y = T; }
      else if(!memcmp(swp,"yz",2) || !memcmp(swp,"zy",2)){ T = Y; Y = Z; Z = T; }
      else if(!memcmp(swp,"zx",2) || !memcmp(swp,"xz",2)){ T = Y; Y = Z; Z = T; }
      else setError("Swap(str*): Wrong components <%c%c>",swp[0],swp[1]);
      return *this;
    }

    Vec Vec::getSwap(const void* cmp)
    {
      cVec v = Vec(); v.Set(this).Swap(cmp); return v;
    }
#endif
