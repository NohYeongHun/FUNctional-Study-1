# 순수함수란?
Pure function = side-effect가 없는 함수, 즉 함수의 실행이 외부에 영향을 끼치지 않는 함수.
따라서 순수함수는 스레드가 안전하고 병렬적인 계산이 가능하다.
ex)  y=f(x)*f(x); /z = f(x); y=z*z
y=f(x)*f(x) == y=z*z 
순수함수의 경우에 오른쪽 식은 f(x)를 계산하는 과정이 두 번에서 한번으로 줄어들지만 두 코드의 결과는
항상 같음.
but y=random() * random();의 경우
z =random(); 
y= random() * random() != y= z*z;




