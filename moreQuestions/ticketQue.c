//inputs: No of tickets, coupon, which class,
// min tickets-5, max -40
// 20 or more 10% discount
// valid coupon 2% additonal
//Class x-75, y-150
#include <stdio.h>
int main(){
	int no, cx, cy;
	printf("Enter the number of tickets in X class : ");
	scanf("%d",&cx);
	printf("Enter the number of tickets in Y class : ");
	scanf("%d",&cy);
	no = cx+cy; // add total number of tickets
	if(no>5 && no<40) {
		int choice;
		float ans;
		ans = cx*75+cy*150;
		ans = no>=20 ? ans-ans*0.10f : ans; // if number of tickets is more than 20 then 10% discount
		printf("Do you have a coupon (1/0) : ");
		scanf("%d",&choice);
		ans = choice ? ans-ans*0.02f : ans; // if user have coupon 2% additional discount
		printf("Total amount : %.2f",ans);
	} else printf("Total number of tickets should be in range 5-40");
}