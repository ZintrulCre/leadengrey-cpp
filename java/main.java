import design_pattern.Builder;
public class main {
    public static void main(String[] args) {
        // leetcode.leetcode();

        CharacterBuilder characterBuilder = new CharacterBuilder();
        Character teenager = characterBuilder.BuildTeenager();
        teenager.info();
    }
}