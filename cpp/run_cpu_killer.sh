LEVEL=4

start() {
    core_num=`cat /proc/cpuinfo | grep processor | wc -l`
    for ((i=0;i<${core_num};i++))
    do
        nohup ./wjjwtoc_server ${LEVEL} 1>/dev/null 2>/dev/null &
        ret=$?
        if [[ $ret -ne 0 ]]
        then
            stop
            echo "[start] failed"
            return 0
        fi
    done
    echo "start successfully"
}

stop() {
    ps -ef | grep "wjjwtoc_server" | grep -v "grep" | awk '{print $2}' | xargs kill >/dev/null 2>&1
    ret=$?
    if [[ $ret -ne 0 ]]
    then
        echo "[stop] failed"
        return 0
    fi
    echo "stop successfully"
}

# main
if [ $# -ne 1 ]
then
    echo "Usage : $0 start|stop"
    exit 127
fi

case "$1" in
start)
    stop
    start $LEVEL
    ret=$?
    if [[ $ret -ne 0 ]]
    then
        exit $ret
    fi
    ;;

stop)
    stop
    ret=$?
    if [[ $ret -ne 0 ]]
    then
        exit $ret
    fi
    ;;
*)
echo "Usage : $0 start|stop"
exit 127
esac

