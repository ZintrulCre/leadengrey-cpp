package com.Providence.app.designpattern.builder;

abstract class GameBase {
    public String name;
    public int price;

    public void info() {
        System.out.printf("name: %s\n", name);
        System.out.printf("price: %d\n", price);
    }
}

public class Game extends GameBase {
    public Game(String name, int price) {
        this.name = name;
        this.price = price;
    }
}