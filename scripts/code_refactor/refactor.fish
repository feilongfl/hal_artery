#!/usr/bin/env fish

set PROCESSDIR at32f43x

function refact
    set script_dir (dirname (status --current-filename))
    echo Refact $argv ...

    # 0. backup origin folders

    # 1. copy at32f43x/cmsis/cm4/device_support
    #    copy at32f43x/drivers

    # 2. drop template

    # 3. rename file to series name
    for f in (find $argv -name "*.c" -or -name "*.h")
        set t (echo $f | sed -r "s/at32f435_437/"$argv"/")
        echo rename: $f =\> $t
        mv $f $t
    end
    # 4. refact symbos
    for f in (find $argv -name "*.c" -or -name "*.h")
        echo refact f43x code: $f
        # 3.1 rename include file in source file
        sed -i "s/at32f435_437/"$argv"/g" $f
        # 3.2 rename __AT32F435_437_XXX to __AT32F43X_XXX
        sed -i s/__AT32F435_437/__AT32F43X/g $f
    end
    for f in (find $argv -name "*.c" -or -name "*.h")
        echo refact include: $f
    end

    # 5. apply code patch
    for cocci in (find $script_dir -name "*.cocci" )
        find $target -name "*.h" -or -name "*.c" | xargs -P0 -n1 $script_dir/eval_patch.fish $cocci
    end
end

refact $PROCESSDIR
