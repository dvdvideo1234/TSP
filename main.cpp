#include <conio.h>
#include <malloc.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "common.h"
#include "mytypes.h"
#include "vector3.h"

int main()
{
  cVec A = Vec("A", 1, 2, 3);

/* Coplanarity
  cVec A = Vec("A", 1, 2, 3);
  cVec B = Vec("B", 4, 5, 6);
  cVec C = Vec("C", 7, 8, 9);
  printf("\nCoplan: %u",A.isCoplanar(&B,&C));
  printf("\nCoplan: %u",A.isCoplanar(B,C));
  printf("\nCoplan: %u",A.isCoplanar(B,&C));
  printf("\nCoplan: %u",A.isCoplanar(&B,C));
*/
/* Mixed product (18)
  cVec A = Vec("A", 1, 2, 3);
  cVec B = Vec("B", 4, 5, 6);
  cVec C = Vec("C", 3, 5, 1);

  printf("\nMix: %f",A.getMix(B,C));
  printf("\nMix: %f",A.getMix(&B,&C));
  printf("\nMix: %f",A.getMix(&B,C));
  printf("\nMix: %f",A.getMix(B,&C));
*/

/* Orthogonal (255)
  cVec A = Vec("A", 1, 2, 3);
  cVec B = Vec("B", 5, -1, -1);

  printf("\nOrth: %u",A.isOrthogonal(B));
  printf("\nOrth: %u",A.isOrthogonal(&B));
*/
/* Collinear
  cVec A = Vec("A", 1, 2, 3);
  cVec B = Vec("B", -2, -4, -6);

  printf("\nColl: %u",A.isCollinear(B));
  printf("\nColl: %u",A.isCollinear(&B));
*/

/* Swap
  A.getSwap("xy").Print();
  A.getSwap("xY").Print();
  A.getSwap("Xy").Print();
  A.getSwap("XY").Print();
  C.Set(A).Swap("xy").Print();
  C.Set(A).Swap("xY").Print();
  C.Set(A).Swap("Xy").Print();
  C.Set(A).Swap("XY").Print();
 */

/* Direction
  A.getDirection().Print();
  C.Set(A).Direction().Print();

  C.Set(A).Direction(B).Print();
  C.Set(A).Direction(&B).Print();
  A.getDirection(B).Print();
  A.getDirection(&B).Print();
*/

/* Projections
  A.getProject(&B).Print();
  A.getProject( B).Print();
  C.Set(A).Project(&B).Print();
  C.Set(A).Project( B).Print();
*/

/* Angles
printf("\n%f, %f, %f, %f",A.getAngleDeg(B),A.getAngleDeg(&B),A.getAngleRad(&B),A.getAngleRad(B));
*/

/* Div
  A.getDiv(2).Print();
  C.Set(&A).Div(2).Print();
  C.Set(&A) /= 2;
  C.Print();
  C = A / 2;
  C.Print();
*/

/* Mul
  A.getMul(2).Print();
  C.Set(&A).Mul(2).Print();
  C.Set(&A) *= 2;
  C.Print();
  C = A * 2;
  C.Print();
*/

/* Sub
  A.getSub(&B).Print();
  A.getSub (B).Print();
  C.Set(&A).Sub(B).Print();
  C.Set(&A).Sub(&B).Print();
  C.Set(&A) -= B;
  C.Print();
  C = A - B;
  C.Print();
*/

/* Add
  A.getAdd(&B).Print();
  A.getAdd (B).Print();
  C.Set(&A).Add(B).Print();
  C.Set(&A).Add(&B).Print();
  C.Set(&A) += B;
  C.Print();
  C = A + B;
  C.Print();
*/

/* Cross product
  A.getCross(&B).Print();
  A.getCross (B).Print();
  C.Set(&A).Cross(B).Print();
  C.Set(&A).Cross(&B).Print();
  C.Set(&A) ^= B;
  C.Print();
  C = A ^ B;
  C.Print();
*/

  return 0;
}
