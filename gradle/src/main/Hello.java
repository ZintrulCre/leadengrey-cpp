package com.leadengrey;

import com.fasterxml.jackson.databind.ObjectMapper;

public class Hello {
    public static void main(String[] args) {
        String json = "{ \"name\" : \"Jack\", \"gender\" : \"male\" }";
        System.out.println(json);
        try {
            ObjectMapper objectMapper = new ObjectMapper();
            Person p = objectMapper.readValue(json, Person.class);
            System.out.println(p);
        }
        catch (Exception e)
        {
            throw new ArithmeticException("error");
        }
    }
}