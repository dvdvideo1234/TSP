#include <conio.h>
#include <malloc.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "mytypes.h"
#include "tspvector.h"

int main()
{
  char border[] = "------------------";

  printf("%30.28lf\n", ((double)TSP_PI));

  cVec A, B, C;

  printf("\n%sFriend Operators%s",border,border);
  A = Vec("A", 1, 2, 3);
  B = Vec("B", 3, 2, 1);

  (A + B).setName("A + B").Print();
  C.setName("A += B");
  C.Set(A) += B;
  C.Print();
  C.setName("A += 4");
  C.Set(A) += 4;
  C.Print();

  (A - B).setName("A - B").Print();
  C.setName("A -= B");
  C.Set(A) -= B;
  C.Print();
  C.setName("A -= 4");
  C.Set(A) -= 4;
  C.Print();

  (A ^ B).setName("A x B").Print();
  C.setName("A x= B");
  C.Set(A) ^= B;
  C.Print();

  (4 * A).setName("4 * A").Print();
  (A * 4).setName("A * 4").Print();
  C.setName("A *= 4");
  C.Set(A) *= 4;
  C.Print();
  C.setName("A = A.Mul(A * B)");
  C.Set(A) *= B;
  C.Print();

  (A / 2).setName("A / 2").Print();
  C.Set(A).setName("A /= 2") /= 2;
  C.Print();

  printf("\n A <  B: %d",A <  B);
  printf("\n A <= B: %d",A <= B);
  printf("\n A >  B: %d",A >  B);
  printf("\n A >= B: %d",A >= B);
  B = Vec("B", 1, 2, 3); printf("\n A == B: %d",A == B);
  B = Vec("B", 1, 3, 3); printf("\n A != B: %d",A != B);

  printf("\n%sStagePrint%s",border,border);
  A = Vec("A", 1, 2, 3);
  B = Vec("B", 3, 2, 1);
  C.Set(A).setName("A").Print().Add(B).setName("A + B").Print().Div(4).setName("A / 4").Print();

  printf("\n%sIncrementsDecrements%s",border,border);
  A = Vec("A", 1, 2, 3);
  B = Vec("B", 4, 5, 6);
  C = Vec("C", 0, 0, 0);
  C.Set(A).setName("C++");
  C++;
  C.Print();
  C.Set(A).setName("C--");
  C--;
  C.Print();

  printf("\n%sDistance%s",border,border);
  A = Vec("A", 1, 2, 3);
  B = Vec("B", 4, 5, 6);
  C = Vec("C", 0, 0, 0);

  printf("\nRelative\n%30.28lf, \n%30.28lf",A.getDistance(B),A.getDistance(&B));
  printf("\nNoOrigin\n%30.28lf, \n%30.28lf",A.getDistance(NULL),A.getDistance());

  printf("\n%sCoplanarity%s",border,border);
  A = Vec("A", 1, 2, 3);
  B = Vec("B", 4, 5, 6);
  C = Vec("C", 7, 8, 9);
  printf("\nCoplan: %u",A.isCoplanar(&B,&C));
  printf("\nCoplan: %u",A.isCoplanar(B,C));
  printf("\nCoplan: %u",A.isCoplanar(B,&C));
  printf("\nCoplan: %u",A.isCoplanar(&B,C));


  printf("\n%sMixed Product%s",border,border);
  A = Vec("A", 1, 2, 3);
  B = Vec("B", 4, 5, 6);
  C = Vec("C", 3, 5, 1);
  printf("\nMix: %f",A.getMix(B,C));
  printf("\nMix: %f",A.getMix(&B,&C));
  printf("\nMix: %f",A.getMix(&B,C));
  printf("\nMix: %f",A.getMix(B,&C));


  printf("\n%sOrthogonality%s",border,border);
  A = Vec("A", 1, 2, 3);
  B = Vec("B", 5, -1, -1);
  printf("\nOrth: %u, %u",A.isOrthogonal(B),A.isOrthogonal(&B));

  printf("\n%sCollinearity%s",border,border);
  A = Vec("A", 1, 2, 3);
  B = Vec("B", -2, -4, -6);
  printf("\nColl: %u, %u",A.isCollinear(B), A.isCollinear(&B));

  printf("\n%sSwapping%s",border,border);
  A.getSwap("xy").Print();
  A.getSwap("xY").Print();
  A.getSwap("Xy").Print();
  A.getSwap("XY").Print();
  C.Set(A).Swap("xy").Print();
  C.Set(A).Swap("xY").Print();
  C.Set(A).Swap("Xy").Print();
  C.Set(A).Swap("XY").Print();

  printf("\n%sDirection%s",border,border);
  A = Vec("A", 1, 2, 3);
  B = Vec("B", 3, 2, 1);
  C = Vec("C", 0, 0, 0);
  A.getDirection().Print();
  A.getDirection(NULL).Print();
  C.Set(A).Direction().Print();
  C.Set(A).Direction(NULL).Print();
  A.getDirection(B).Print();
  A.getDirection(&B).Print();
  C.Set(A).Direction(B).Print();
  C.Set(A).Direction(&B).Print();

  printf("\n%sProject%s",border,border);
  A = Vec("A", 1, 2, 3);
  B = Vec("B", 3, 2, 1);
  C = Vec("C", 0, 0, 0);
  A.getProject(&B).Print();
  A.getProject( B).Print();
  C.Set(A).Project(&B).Print();
  C.Set(A).Project( B).Print();


  printf("\n%sAngles%s",border,border);
  printf("\n%f, %f, %f, %f",A.getAngleDeg(B),A.getAngleDeg(&B),A.getAngleRad(&B),A.getAngleRad(B));

  printf("\n%sDivide%s",border,border);
  A = Vec("A", 1, 2, 3);
  B = Vec("B", 3, 2, 1);
  C = Vec("C", 0, 0, 0);
  A.getDiv(2).Print();
  C.Set(&A).Div(2).Print();
  C.Set(&A) /= 2;
  C.Print();
  C = A / 2;
  C.Print();


  printf("\n%sMultiply%s",border,border);
  A = Vec("A", 1, 2, 3);
  B = Vec("B", 3, 2, 1);
  C = Vec("C", 0, 0, 0);
  A.getMul(2).Print();
  C.Set(&A).Mul(2).Print();
  C.Set(&A) *= 2;
  C.Print();
  C = A * 2;
  C.Print();

  printf("\n%sSubstract%s",border,border);
  A = Vec("A", 1, 2, 3);
  B = Vec("B", 3, 2, 1);
  C = Vec("C", 0, 0, 0);
  A.getSub(&B).Print();
  A.getSub (B).Print();
  C.Set(&A).Sub(B).Print();
  C.Set(&A).Sub(&B).Print();
  C.Set(&A) -= B;
  C.Print();
  C = A - B;
  C.Print();

  printf("\n%sAddition%s",border,border);
  A = Vec("A", 1, 2, 3);
  B = Vec("B", 3, 2, 1);
  C = Vec("C", 0, 0, 0);
  A.getAdd(&B).Print();
  A.getAdd (B).Print();
  C.Set(&A).Add(B).Print();
  C.Set(&A).Add(&B).Print();
  C.Set(&A) += B;
  C.Print();
  C = A + B;
  C.Print();

  printf("\n%sCross%s",border,border);
  A = Vec("A", 1, 2, 3);
  B = Vec("B", 3, 2, 1);
  C = Vec("C");
  A.getCross(&B).Print();
  A.getCross (B).Print();
  C.Set(&A).Cross(B).Print();
  C.Set(&A).Cross(&B).Print();
  C.Set(&A) ^= B;
  C.Print();
  C = A ^ B;
  C.Print();

  printf("\n%sArea%s",border,border);
  A = Vec("A", 1, 2, 3);
  B = Vec("B", 3, 2, 1);
  C = Vec("C",4,-10,4);
  printf("\nTri = \n%30.28lf, \n%30.28lf, \n%30.28lf",
         A.getAreaTriangle(B),
         A.getAreaTriangle(&B),
         A.getAreaTriangle(NULL));
  printf("\nPar = \n%30.28lf, \n%30.28lf, \n%30.28lf",
         A.getAreaParallelogram(B),
         A.getAreaParallelogram(&B),
         A.getAreaParallelogram(NULL));

  printf("\n%sVolume%s",border,border);
  printf("\nHyd = \n%30.28lf, \n%30.28lf, \n%30.28lf, \n%30.28lf, \n%30.28lf, \n%30.28lf, \n%30.28lf",
         A.getVolumeTetrahedron(B,C),
         A.getVolumeTetrahedron(&B,&C),
         A.getVolumeTetrahedron(&B,C),
         A.getVolumeTetrahedron(B,&C),
         A.getVolumeTetrahedron(NULL,C),
         A.getVolumeTetrahedron(B,NULL),
         A.getVolumeTetrahedron(NULL,NULL));

  return 0;
}







