RESULT="0"
for i in `find -name *.d` 
do rm $i
done

echo "removed all dependencies (*.d files) "
