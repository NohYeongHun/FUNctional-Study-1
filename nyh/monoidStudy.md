# 순수언어(Pure languages) vs 불순언어(Impure languages)

# monad monoid
- Monad μ::T2→Tη::I→Tμ(T,μ(T2))=μ(μ(T2),T)μ(η(I),T)=μ(T,η(I))=T​​
- Monoid ⊗::T×T→Tit1​⊗(t2​⊗t3​)=(t1​⊗t2​)⊗t3​i⊗t=t⊗i=t


# 질문
- 순수언어, 불순한 언어의 차이점?
ex ) 순수언어 : 하스켈 
     불순언어 : 그외
- unit(return) operator
- bind operator가 있어야 한다.
- 바인딩이란? int num =123;
- 이름, 자료형, 자료값에 각각 num, int ,123 이라는 구체적인 값을 할당하는 각각의 과정이 바인드
- 해당 기능 "a"이런식으로 사용하지 못하게하는??=>\<a>\</a>
: ->해당하는 기능 앞에 "\"를 붙여주면 기능이 깨진다.

# 모나드의 간단 정의
어떤 타입 M에 대해 아래의 두 함수, pure과 compose가 존재할 때, M은 모나드입니다.
모나드는 연산을 정의하고 추상화 하기 위해 쓰이는 것
제네릭 프로그래밍은 여러 데이터들에 대해 일반적인, 즉 유연한 코드를 작성함으로서 재사용성을 끌어올림.
즉 모나드는 '합칠 수 있는 연산'을 정의하고 추상화 하기 위해 사용한다.
'어떤 연산이 모나드로 정의된다면, 그 연산에 해당하는 모든 프로그램은 합쳐질 수 있다.'
ex) 입출력 연산 

# 모나드 사용 이유
순수한 기능적 언어에 불순한 효과를 통합하기 위해 모나드, 범주 이론에서 비롯된
모나드 개념이 적용되었다.
프로그래밍 적으로 다음 세 가지를 충족시 모나드 라고 부를 수 있다.
1. 타입을 인자로 받는 타입이다. 
// 타입 생성자 ex) c++ templete와 유사하며 다른 타입을 인자로 받는다.
2. unit(return) operator가 있어야 한다. ex) return 함수
리턴의 의미가 살짝 다름. return:: a-> M a
타입 'a'를 받아 M a 방식으로 반환.
3. bind operator가 있어야 한다. 
바인드 연산자가 있어야한다. ex) >>==

# 모나드, 바인드 연산자 그리고 순수함수
모나드를 이용해 부작용(Side Effect)이 없는 함수, 즉 순수함수를 만드는데 이용.
외부 상태를 인수로 전달, 결과로 상태값을 반환.
ex) 외부상태 타입 = State 함수 f, g 존재 a,b는 또다른 결과값
f:: State -> (a, State)
g:: State -> (b, State)

- 바인드 연산자의 사용이유 
함수 합성g(f(x))해야 할 일이생기면?
f의 출력과 g의 입력이 맞지 않음. => g(f(x)) => g:: State -> (f(a,State), State)
f의 결과값을 a와 state로 분리하고,
a는 g와 결합해 새로운 함수 g`를 만들어 주며
Stage를 g`에 전달해줌
바인드 연산자가 만들어준 새로운 함수 g`는
g`:: State -> (b, State)의 형태가 되도록함
f::State -> (a,State)
g::State -> (b,State)
g(f(x))

- 참고 이미지 주소
https://img1.daumcdn.net/thumb/R1280x0/?scode=mtistory2&fname=https%3A%2F%2Fblog.kakaocdn.net%2Fdn%2FmVJuT%2FbtqBZfs4hs8%2FmoXQkAKQKHEmp7X6dE3Kc1%2Fimg.png

# code 1
```
val maybeValue: Maybe<Int> = Maybe.just(14)//(1)
maybeValue.subscribeBy(//(2)
  onComplete = {println("Completed Empty")},
  onError = {println("Error $it")},
  onSuccess = { println("Completed with value $it")}
)
val maybeEmpty:Maybe<Int> = Maybe.empty()//(3)
maybeEmpty.subscribeBy(//(4)
  onComplete = {println("Completed Empty")},
  onError = {println("Error $it")},
  onSuccess = { println("Completed with value $it")}
)
모나드인 Maybe는 값을 포함할 수도, 포함하지 않을수도 있는 타입이며, 
방출된 결과 값, 혹은 오류에 상관없이 완료가 됩니다. 
Maybe는 총 세가지의 터미널 메서드를 가지고 있는데, 오류가 발생 시 onError 함수가 
호출이 되어 이에 대한 구현 처리를 하게됩니다. 
또는 성공시에는 onSucess 함수가 호출이되어 성공에 대한 구현 처리를 하게됩니다. 
값도 없고, 오류도 없는 경우엔 최종적으로 완료하여 onComplete 함수를 호출하게 됩니다.

먼저 주석(1)에서는 모나드를 선언하고, 14라는 값을 주입(할당)합니다. 주석(2)에서는 subscribeBy 함수를 통해 구독을 시작하게 됩니다. 
그리고 해당 구독에 대한 터미널 메서드로 각 상황에 맞는 함수를 구현해주게 됩니다.
주석(3)에서는 빈값으로 선언을 하였습니다. 빈값에 대한 구독이기 때문에 주석(4)로 구독 시 바로 완료처리가 될 것입니다.

다음은 결과입니다.
Completed with value 14
Completed Empty
```

# code 2
```
class FamilyTree {
    @Getter
    @AllArgsConstructor
    class Person {
        private String relation;
        private Person father;
        private Person mother;
    }

    Person createFamilyTree() {
        return new Person("Me",
                new Person("Father",
                        new Person("GrandFather",
                                new Person(null,                null, null),
                                new Person("Great-GrandMother", null, null)),
                        new Person("GrandMother", null, null)),
                new Person("Mother",
                        new Person("Maternal GrandFather", null, null),
                        new Person("Maternal GrandMother", null, null)));
    }

    Person person;
    FamilyTree() {
        this.person = createFamilyTree();
    }
...

사람(Person)
관계, 아버지, 어머니 정보를 가진다.
생성자로 생성된 사람한계
친가: 친증조할아버지(이름 누락), 친증조할머니
외가: 외할아버지, 외할머니

void find1() {
    if ( person.getFather() != null ) {
        Person father = person.getFather();
        if ( father.getFather() != null ) {
            Person grandFather = father.getFather();
            if ( grandFather.getFather() != null ) {
                Person greatGrandFather = grandFather.getFather();
                if ( greatGrandFather.getRelation() != null )
                    System.out.println( "1-1: " + greatGrandFather.getRelation() );
                else
                    System.out.println( "1-1: Failed" );
            } else {
                System.out.println( "1-1: Failed" );
            }
        }  else {
            System.out.println( "1-1: Failed" );
        }
    } else {
        System.out.println( "1-1: Failed" );
    }

    if ( person.getMother() != null ) {
        Person mother = person.getMother();
        if ( mother.getMother() != null ) {
            Person maternalGrandMother = mother.getMother();
            if ( maternalGrandMother.getRelation() != null )
                System.out.println( "1-2: " + maternalGrandMother.getRelation() );
            else
                System.out.println( "1-2: Failed" );
        } else {
            System.out.println( "1-2: Failed" );
        }
    } else {
        System.out.println( "1-1: Failed" );
    }
}

// 간소화
void find2() {
    Optional.of( person )
        .map( Person::getFather   )
        .map( Person::getFather   )
        .map( Person::getFather   )
        .map( Person::getRelation )
        .ifPresentOrElse(
            info -> System.out.println( "2-1: " + info ),
            ()   -> System.out.println( "2-1: Failed"  )
        );

    Optional.of( person )
        .map( Person::getMother   )
        .map( Person::getMother   )
        .map( Person::getRelation )
        .ifPresentOrElse(
            info -> System.out.println( "2-2: " + info ),
            ()   -> System.out.println( "2-2: Failed"  )
        );
    }

}

모나드의 개념을 이용해서 바라보면

Optional.of()는 Optional 타입 모나트 생성자 역할로 person을 감싸준다. (타입 생성자, return)
map 함수를 연속적으로 적용 또는 합성한다. (바인드 연산자, chaining)
마지막으로 Optional 타입을 이용해서 Null값 여부를 확인한다.
영락없는 모나드의 형태며,  적용되는 것을 보면 do 연산자를 보는 느낌이 든다.

```


# reference
<br>
[간단한 모나드설명]https://black7375.tistory.com/69
<br>
[3분 모나드]https://overcurried.com/3%EB%B6%84%20%EB%AA%A8%EB%82%98%EB%93%9C/
