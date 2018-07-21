MEM_CONTAINER=./mem_container 
MEM_LIMIT_M=100

param=$1
${MEM_CONTAINER} --mem_limit=${MEM_LIMIT_M} --task_command="sh run_2s.sh && abc ${param} "

asd

TASK_RESULT=$?
if [ ${TASK_RESULT} -ne 0 ]
then
    echo "error detect lane, errno:${TASK_RESULT}"
    echo $[TASK_RESULT+1002000]
    exit ${TASK_RESULT}
fi

echo "ok"
