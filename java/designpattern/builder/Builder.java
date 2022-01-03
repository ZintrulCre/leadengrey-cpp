package designpattern.builder;

public class Builder {
    public Game buildWoW() {
        return new Game("Wow", 75);
    }
}
