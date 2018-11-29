import junit.framework.TestCase;
import org.junit.Test;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {

public void testSchmePartition(){
   UrlValidator urlValidator= new UrlValidator(null, null, 0);
   assert urlValidator.isValid("http://google.com") == true: "correct scheme is not passing isValid";
   assert urlValidator.isValid("hp://google.com") == false: "valid scheme is passing isValid";
   assert urlValidator.isValid("hTTp://google.com") == true: "correct scheme is not passing isValid";
   assert urlValidator.isValid("http:/google.com") == false: "valid scheme is passing isValid";
   assert urlValidator.isValid("http:|/google.com") == false: "valid scheme is passing isValid";
}

public void testAuthorityPartition(){
    UrlValidator urlValidator= new UrlValidator(null, null, 0);
    assert urlValidator.isValid("google.5h") == false: "valid authority is passing isValid";
    assert urlValidator.isValid("1.23.212.1") == false: "valid authority is passing isValid";
    assert urlValidator.isValid("http://Google.com") == true: "correct authority is not passing isValid";
    assert urlValidator.isValid("http://google.coM") == true: "correct authority is not passing isValid";
    assert urlValidator.isValid("http://0.0.0.0") == true: "correct authority is not passing isValid";
    assert urlValidator.isValid("") == false: "valid authority is passing isValid";
    assert urlValidator.isValid("http://google.com") == true: "correct authority is not passing isValid";


}

public void testPortPartition(){
    UrlValidator urlValidator= new UrlValidator(null, null, 0);
    assert urlValidator.isValid("http://google.com:123") == true: "correct port is not passing isValid";
    assert urlValidator.isValid("http://google.com:123GH") == true: "valid port is passing isValid";
    assert urlValidator.isValid("http://google.com:GHFD") == true: "valid port is passing isValid";
}

public void testPathPartition(){
    UrlValidator urlValidator= new UrlValidator(null, null, 0);
    assert urlValidator.isValid("http://google.com/file") == true: "correct path is not passing isValid";
    assert urlValidator.isValid("http://google.com/File") == true: "correct path is not passing isValid";
    assert urlValidator.isValid("http://google.com/file123") == true: "correct path is not passing isValid";
    assert urlValidator.isValid("http://google.com/....../file") == false: "valid path is passing isValid";
    assert urlValidator.isValid("http://google.com/....") == false: "valid path is passing isValid";
}

public void testQueryPartition(){
    UrlValidator urlValidator= new UrlValidator(null, null, 0);
    assert urlValidator.isValid("http://google.com?action=hide") == true: "correct path is not passing isValid";
}


}