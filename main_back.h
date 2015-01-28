  /*

  f32 a;
    cVec *T = new cVec(1,1,1);
    cVec A = Vec("A",1,2,3);
    cVec B = Vec("B",3,2,1);
    cVec C = Vec("C",0,12,0);
    cVec D = Vec("D");
    cVec E = Vec("E");
    cVec F = Vec("F");
    cVec G = Vec("G");
    cVec H = Vec("H");
    cVec I = Vec("I");
    cVec J = Vec("J");
    cVec K = Vec("K");

    A.setNext(&B);
    B.setNext(&C);
    C.setNext(&D);
    D.setNext(&E);
    E.setNext(&F);
    F.setNext(&G);
    G.setNext(&H);
    H.setNext(&I);
    I.setNext(&J);

    J.setName("Master Yoda").setNext(&K).Set(2,2,2).Mul(1.5);
    K.setNext(T).Add(&A);
    T->Set(1,1,1).setName("Test").Offset(A,10).Mul(0.3).Normalize().setNext(NULL);


    C.Set(A.getCross(B));
    D.Set(A.getProjected(&B));
    E.Set(A+B).Mul(A*B);

    T->Print();

    // delete T;

    T->~Vec();


    T->Print();

    T = new Vec(E.getDirByOrigin(NULL));

    T->Print();

    E.Offset(T,4).Mul(4);

    F.Set(2,2,2);

    F /= 2;
    F *= 3.56;
    F -= A;
    F *= A;
    F ^= C;

    F.Print();
    G.Set(A * 2);
    H.Set(A ^ B).Neg().Div(4);
    I.Set(A.getDirByOrigin(&B));
    J.Set(*(&F) + F + (2 * A));
    K.Set(Vec(A.getDirCos('x'),A.getDirCos('y'),A.getDirCos('z')));
    K.setName("Obi-One!");
    I.setName("Jedi !");
    a = 555.5555;

    K.setY(0);

    K.Set(1,1,1);

    K.Mul(2);
    K.Mul(2).Mul(2).Set(1,2,3);


    A.RollR();
    A.Swap("zy");


    C += ((A+B) ^ C);

    // Privatizations and violations !!!
    *(((u32*)(&K)) + 2) = *((u32*)(&a));

    A.PrintTrajectory();
*/
