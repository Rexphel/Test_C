// Generate 'bullshit sentences'
// TO DO 1: In lines v=, n=, a=, ... rand%12? Why always 12?
// TO DO 2: Create more complex sentences e.g. by using more adjectives together or by concatenating several phrases.
// TO DO 3: Generalize the 'You should' by allowing other random introductions, e.g. "we have to", "our company must"
// TO DO 4: Don't write the output to the screen but copy the whole phrase into a separate string.
// Source of words see: http://dack.com/web/bullshit.html

#include <stdio.h> 
#include <stdlib.h>

int number, v, n, a, a1, a2, a3, F;

int Check_Double(){
	int i = 0;
	while (!i)
	{
		if (a == a1)
		{
			a=rand()%13;
		}
		else if (a == a2)
		{
			a2=rand()%13;
		}
		else if (a == a3)
		{
			a3=rand()%13;
		}
		else if (a1 == a2)
		{
			a1=rand()%13;
		}
		else if (a1 == a3)
		{
			a3=rand()%13;
		}
		else if (a2 == a3)
		{
			a2=rand()%13;
		}
		else
		{
			break;
		}
	}

	
}

int main( ) {
	setvbuf (stdout, NULL, _IONBF, 0);
	char verbs[][20]={ "benchmark", "exploit", "facilitate", "generate", "implement", "leverage", "maximize",
		"mesh", "monetize", "optimize", "orchestrate", "redefine" };
	char First[][20]={ "You should", "We have to", "Our Company must", "It is our dutie to" };
	char nouns[][20]={ "action-items", "applications", "bandwidth", "communities", "e-business", "experiences", 
		"infrastructures", "methodologies", "partnerships", "synergies", "solutions", "technologies" };
	char adjectives[][20]={ "bleeding-edge", "collaborative", "cross-platform", "distributed", "efficient",
		"global", "holistic", "innovative", "mission-critical", "next-generation", "out-of-the-box", "user-centric", "" };

	printf("How much bullshit do you need?");
	scanf("%d", &number);
    
	while(number>0) 
	{
		F=rand()%4;
		v=rand()%12;
		n=rand()%12;
		a=rand()%13;
		a1=rand()%13;
		a2=rand()%13;
		a3=rand()%13;

		Check_Double();

		printf("Your boss says: %s %s %s %s %s %s %s!\n",First[F],verbs[v],adjectives[a],adjectives[a1],adjectives[a2],adjectives[a3],nouns[n]);
		number=number-1;
	}
scanf("%d", &number);
}

