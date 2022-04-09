package com.leadengrey;

import lombok.Data;
import lombok.AllArgsConstructor;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class Person {
    public String name;
    public String gender;

    @Override
    public String toString() {
        String str = new String();
        str += "name: " + name + "\n";
        str += "gender: " + gender;
        return str;
    }
}
