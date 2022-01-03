public class CharacterBuilder {
    Character BuildTeenager() {
        return new Character("Joel", 26, 1);
    }
}

abstract class CharacterBase {
    public String name;
    public int gender;
    public int age;

    public void Info() {
        System.out.printf("name: %s\n", name);
        System.out.printf("gender: %d\n", gender);
        System.out.printf("age: %d\n", age);
    }
}

final class Character extends CharacterBase{
    public Character(String name, int gender, int age) {
        this.name = name;
        this.gender = gender;
        this.age = age;
    }
}