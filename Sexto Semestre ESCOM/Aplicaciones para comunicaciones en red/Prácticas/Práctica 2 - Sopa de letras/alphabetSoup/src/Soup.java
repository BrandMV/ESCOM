
import java.util.Random;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author PC
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
    
    public void setSoup(){
//        for(String word : words){
//            rand = new Random();
//            Integer fillAction = 8; //*To generate random word orientation
//            Integer randomAction = rand.nextInt(fillAction);    //*Generating random number between 0 - 7
//            setOrientation(randomAction, word);
//        }

        for(int i = 0; i < words.length; i++){
            String currentWord = words[i];
            rand = new Random();
            
            
            Integer limitRow = 14;
            Integer limitColumn = 14;
            //*Word long
            Integer letters = currentWord.length();
            //*Random word position 
            Integer rowPosition = rand.nextInt(limitRow);
            Integer columnPosition = rand.nextInt(limitColumn);

            //*Checking if space is enough
            Integer aCol = (limitColumn + 1) - columnPosition;
            Integer aRow = (limitRow + 1) - rowPosition;
            
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

    
    public void vertical(Integer lWord, Integer rowPos, Integer colPos, String word){
        for(int i = 0; i < lWord; i++){
            soup[rowPos+i][colPos] = "" + word.charAt(i);
//            rowPos++;
        }
    }
    
    public void horizontal(Integer lWord, Integer rowPos, Integer colPos, String word){
        for(int i = 0; i < lWord; i++){
            soup[rowPos][colPos+i] = ""+word.charAt(i);
        }
    }
    
    public void invertedVertical(Integer lWord, Integer rowPos, Integer colPos, String word){
       for(int i = 0; i < lWord; i++){
            soup[rowPos-i][colPos] = ""+word.charAt(i);
       } 
    }
    
    public void invertedHorizontal(Integer lWord, Integer rowPos, Integer colPos, String word){
        for(int i = 0 ; i < lWord; i++){
            soup[rowPos][colPos-i] = ""+word.charAt(i);
        }
    }
    
    public void rightDiagonal(Integer lWord, Integer rowPos, Integer colPos, String word){
        for(int i = 0; i < lWord; i++){
            soup[rowPos-i][colPos+i] = ""+word.charAt(i);
        }
    }
    
    public void leftDiagonal(Integer lWord, Integer rowPos, Integer colPos, String word){
        for(int i = 0; i < lWord; i++){
            soup[rowPos-i][colPos-i] = "" + word.charAt(i);
        }
    }
    public void rightDownDiagonal(Integer lWord, Integer rowPos, Integer colPos, String word){
        for(int i = 0; i < lWord; i++){
            soup[rowPos+i][colPos+i] = "" + word.charAt(i);
        }
    }
    public void leftDownDiagonal(Integer lWord, Integer rowPos, Integer colPos, String word){
        for(int i = 0; i < lWord; i++){
            soup[rowPos+i][colPos-i] = "" + word.charAt(i);
        }
    }
    
 
    
    public boolean isWordCollapsed(Integer orientation, Integer colPos, Integer rowPos, Integer lWord){
        
        boolean isCollapsed = false;
        
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
            for(int i = rowPos, j = colPos; i < ( rowPos + lWord ) && j > ( colPos - lWord ); i++,j++){
               if(soup[i][j] != null){
                   isCollapsed = true;
               }
           }
        }
        
        return isCollapsed;
    }
}
