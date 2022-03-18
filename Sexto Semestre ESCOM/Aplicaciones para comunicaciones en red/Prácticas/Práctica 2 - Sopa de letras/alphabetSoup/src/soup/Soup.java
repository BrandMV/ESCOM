package soup;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Random;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author BrandMV
 */
public class Soup {
    private Integer rows;
    private Integer columns;
    private String[][] soup;
    private String[] words;
    Random rand;
    
    public Soup(Integer rows, Integer columns, String[] words){
        this.rows = rows;
        this.columns = columns;
        this.soup = new String[rows][columns];
        this.words = words;
    }
    public Soup(){
        
    }
    
    /**
     * @brief Method that set all the soup
     */
    public void setSoup(){

        for(int i = 0; i < words.length; i++){
            String currentWord = words[i];
            rand = new Random();
  
            Integer limitRow = 15;
            Integer limitColumn = 15;
            //*Word long
            Integer letters = currentWord.length();
            //*Random word position 
            Integer rowPosition = rand.nextInt(limitRow);
            Integer columnPosition = rand.nextInt(limitColumn);

            //*Checking if space is enough
            Integer aCol = (limitColumn ) - columnPosition;
            Integer aRow = (limitRow ) - rowPosition;
            
            Integer aDRow;
            Integer aLRow;
            Integer aDRDRow;
            Integer aDLDRow;
            
            //*Stablishing rightDiagonal space
            aDRow = (aCol < (rowPosition+1) ) ? aCol : rowPosition+1;
            if(aCol == rowPosition+1){
                aDRow = aCol;
            }
            //*Stablishing leftDiagonal space
            aLRow = (( columnPosition + 1 ) < ( rowPosition + 1 ) ? columnPosition + 1 : rowPosition + 1);
            if( columnPosition + 1 == rowPosition + 1){
                aLRow = columnPosition + 1;
            }
            
            //*Stablishing right Diagonal down space
            aDRDRow = ( aCol < aRow ) ? aCol : aRow;
            if(aCol == aRow){
                aDRDRow = aCol;
            }
            
            //*Stablishing left Diagonal down space
            aDLDRow = ( columnPosition + 1 < aRow ) ? columnPosition + 1 : aRow;
            if( columnPosition + 1 == aRow ){
                aDLDRow = columnPosition + 1;
            }
            
            Integer fillAction = 8; //*To generate random word orientation
            Integer randomAction = rand.nextInt(fillAction);    //*Generating random number between 0 - 7
         
//            Integer action = setOrientation(randomAction);
            //*If that verifies the orientation and if there's space enouth to place the word in that orientation
            if(
                (aRow >= letters && randomAction == 0) || (aCol >= letters && randomAction == 1) || (rowPosition+1 >= letters && randomAction == 2)
                || (columnPosition+1 >= letters && randomAction == 3) || ( aDRow >= letters && randomAction == 4 ) || ( aLRow >= letters && randomAction == 5 )
                || ( aDRDRow >= letters && randomAction == 6 ) || ( aDLDRow >= letters && randomAction == 7 )
                    
              ){
                if(!isWordCollapsed(randomAction, columnPosition, rowPosition, letters)){
             
                    switch(randomAction){
                        case 0:
                            vertical(letters, rowPosition, columnPosition, currentWord);
                            break;
                        case 1:
                            horizontal(letters, rowPosition, columnPosition, currentWord);
                            break;
                        case 2:
                            invertedVertical(letters, rowPosition, columnPosition, currentWord);
                            break;
                        case 3:
                            invertedHorizontal(letters, rowPosition, columnPosition, currentWord);
                            break;
                        case 4:
                            rightDiagonal(letters, rowPosition, columnPosition, currentWord);
                            break;
                        case 5:
                            leftDiagonal(letters, rowPosition, columnPosition, currentWord);
                            break;
                        case 6:
                            rightDownDiagonal(letters, rowPosition, columnPosition, currentWord);
                            break;
                        case 7:
                            leftDownDiagonal(letters, rowPosition, columnPosition, currentWord);
                            break;
                        default:
                            System.err.println("Not valid orientation");
                            break;
                    }
                    
                } else i--; //*Taking other position if there's collision
            } else i--; //*Taking other positions if there's no enough space for place the word
            
        }
    }

    /**
     * Method that places a word in the vertical orientation inside the soup
     * @param {Integer} lWord the word longitude
     * @param {Integer} rowPos the row position in the soup
     * @param {Integer} colPos the column position un the soup
     * @param {String} word  The word to place in
     */
    public void vertical(Integer lWord, Integer rowPos, Integer colPos, String word){
        for(int i = 0; i < lWord; i++){
            soup[rowPos+i][colPos] = "" + word.charAt(i);
//            rowPos++;
        }
    }
    
    /**
     * Method that places a word in the horizontal orientation inside the soup
     * @param {Integer} lWord the word longitude
     * @param {Integer} rowPos the row position in the soup
     * @param {Integer} colPos the column position un the soup
     * @param {String} word  The word to place in
     */
    public void horizontal(Integer lWord, Integer rowPos, Integer colPos, String word){
        for(int i = 0; i < lWord; i++){
            soup[rowPos][colPos+i] = ""+word.charAt(i);
        }
    }
    
    /**
     * Method that places a word in the inverted verrtical orientation inside the soup
     * @param {Integer} lWord the word longitude
     * @param {Integer} rowPos the row position in the soup
     * @param {Integer} colPos the column position un the soup
     * @param {String} word  The word to place in
     */
    public void invertedVertical(Integer lWord, Integer rowPos, Integer colPos, String word){
       for(int i = 0; i < lWord; i++){
            soup[rowPos-i][colPos] = ""+word.charAt(i);
       } 
    }
    
    /**
     * Method that places a word in the inverted horizontal orientation inside the soup
     * @param {Integer} lWord the word longitude
     * @param {Integer} rowPos the row position in the soup
     * @param {Integer} colPos the column position un the soup
     * @param {String} word  The word to place in
     */
    public void invertedHorizontal(Integer lWord, Integer rowPos, Integer colPos, String word){
        for(int i = 0 ; i < lWord; i++){
            soup[rowPos][colPos-i] = ""+word.charAt(i);
        }
    }
    
    /**
     * Method that places a word in the right diagonal orientation inside the soup
     * @param {Integer} lWord the word longitude
     * @param {Integer} rowPos the row position in the soup
     * @param {Integer} colPos the column position un the soup
     * @param {String} word  The word to place in
     */
    public void rightDiagonal(Integer lWord, Integer rowPos, Integer colPos, String word){
        for(int i = 0; i < lWord; i++){
            soup[rowPos-i][colPos+i] = ""+word.charAt(i);
        }
    }
    
    /**
     * Method that places a word in the left diagonal orientation inside the soup
     * @param {Integer} lWord the word longitude
     * @param {Integer} rowPos the row position in the soup
     * @param {Integer} colPos the column position un the soup
     * @param {String} word  The word to place in
     */
    public void leftDiagonal(Integer lWord, Integer rowPos, Integer colPos, String word){
        for(int i = 0; i < lWord; i++){
            soup[rowPos-i][colPos-i] = "" + word.charAt(i);
        }
    }
    
    /**
     * Method that places a word in the right down vertical orientation inside the soup
     * @param {Integer} lWord the word longitude
     * @param {Integer} rowPos the row position in the soup
     * @param {Integer} colPos the column position un the soup
     * @param {String} word  The word to place in
     */
    public void rightDownDiagonal(Integer lWord, Integer rowPos, Integer colPos, String word){
        for(int i = 0; i < lWord; i++){
            soup[rowPos+i][colPos+i] = "" + word.charAt(i);
        }
    }
    
    /**
     * Method that places a word in the left down diagonal orientation inside the soup
     * @param {Integer} lWord the word longitude
     * @param {Integer} rowPos the row position in the soup
     * @param {Integer} colPos the column position un the soup
     * @param {String} word  The word to place in
     */
    public void leftDownDiagonal(Integer lWord, Integer rowPos, Integer colPos, String word){
        for(int i = 0; i < lWord; i++){
            soup[rowPos+i][colPos-i] = "" + word.charAt(i);
        }
    }
    
 
    /**
     * @brief Method that stablish if a word is collapsed or not inside the soup
     * @param {Integer} orientation the word orientation
     * @param {Integer} colPos the column position
     * @param {Integer} rowPos the row position
     * @param {Integer} lWord the word longitude
     * @return {boolean} isCollapsed wether if the word is collapsed or not
     */
    public boolean isWordCollapsed(Integer orientation, Integer colPos, Integer rowPos, Integer lWord){
        
        boolean isCollapsed = false;
        
        try {
            //*Vertical
        if( orientation == 0){
            for(int i = rowPos; i < rowPos + lWord; i++){
                if(soup[i][colPos] != null){
                    isCollapsed = true;
                }
            }
        }
        
        //*Horizontal
        if( orientation == 1){
            for(int  i = colPos; i < colPos + lWord; i++){
                if(soup[rowPos][i] != null){
                    isCollapsed = true;
                }
            }
        }
        
        //*Inverted Vertical
        if( orientation == 2){
            for(int i = rowPos; i > rowPos - lWord; i--){
                if(soup[i][colPos] != null){
                    isCollapsed = true;
                }
            }
        }
        
        //*Inverted Horizontal
        if( orientation == 3){
            for(int i = colPos; i > colPos - lWord; i--){
                if(soup[rowPos][i] != null){
                    isCollapsed = true;
                }
            }
        }
        
        //*Right diagonal
        if( orientation == 4){
           for(int i = rowPos, j = colPos; i > ( rowPos - lWord ) && j < ( colPos + lWord ); i--,j++){
               if(soup[i][j] != null){
                   isCollapsed = true;
               }
           }
        }
        
        //*Left diagonal
        if( orientation == 5){
            for(int i = rowPos, j = colPos; i > ( rowPos - lWord ) && j > ( colPos - lWord ); i--,j--){
               if(soup[i][j] != null){
                   isCollapsed = true;
               }
           }
        }
        
        //*Right diagonal down
        if( orientation == 6){
            for(int i = rowPos, j = colPos; i < (lWord + rowPos) && j < (colPos + lWord); i++,j++ ){
                if(soup[i][j] != null){
                    isCollapsed = true;
                }
            }
        }
        
        //*Left diagonal down
        if( orientation == 7){
            for(int i = rowPos, j = colPos; i < ( rowPos + lWord ) && j > ( colPos - lWord ); i++,j--){
               if(soup[i][j] != null){
                   isCollapsed = true;
               }
           }
        }
       
        } catch (Exception e) {
            System.err.println("Exception caught");
        }
        return isCollapsed;
    }
    
    /**
     * @brief Method that fills the soup with random letters took from the alphabet
     */
    public void fillSoup(){
        String alphabet = "abcdefghijklmnñopqrzuv";
       
          for (int i = 0 ; i<soup.length;i++){
            Random rand = new Random();
        
            int randomInt = rand.nextInt(alphabet.length());
            for (int j = 0; j<soup[0].length;j++){
                if (soup[i][j] == null){
                    soup[i][j] = "" + alphabet.charAt(randomInt);
                }
            }
      
        }
    }
    
    /**
     * @brief Method that show the soup
     * @param {String[][]} aSoup The matrix that contains the soup
     */
    public void showSoup(String aSoup[][]){
        System.out.println("i\tj 0\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\t11\t12\t13\t14");
        for (int i = 0 ; i<aSoup.length;i++){
            System.out.print(i);
            for (int j = 0; j<aSoup[0].length;j++){
                if (j!=aSoup[0].length){
                    System.out.print("\t" + aSoup[i][j]);
                }
               
            }
            System.out.println("");
        }
    }

    /**
     * @brief soup getter
     * @return {String[][]} soup the soup created previously
     */
    public String[][] getSoup() {
        return soup;
    }
    
    
}

